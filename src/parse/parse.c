/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:01:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 10:27:31 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static void	add_arg(t_simple_command *c, char arg[MAX_TAB]);
static void	fd_gestion(t_command *command, t_token tk[MAX_TAB], int *i);
static void	reset_command(t_command *cmd);
static void	fd_in_out(t_command *c, t_token tk[MAX_TAB], int *i);

void	ft_parse(t_command *command, t_token token[MAX_TAB])
{
	int	i;

	reset_command(command);
	i = 0;
	command->n = 1;
	while (i < MAX_TAB && token[i].type)
	{
		if (token[i].type >= SINGLE_QUOTE_STR && token[i].type <= ENV_VAR)
			add_arg(&command->s_command[command->n - 1], token[i].content);
		fd_gestion(command, token, &i);
		if (token[i].type == PIPE)
		{
			command->n++;
			if (!token[i + 1].type)
			{
				ft_printf_error("Unexpected last token : %s\n",
					token[i].content);
				command->is_valid = 0;
			}
		}
		i++;
	}
	if (!i)
		command->is_valid = 0;
}

static void	reset_command(t_command *cmd)
{
	int	i;
	int	j;

	i = 0;
	cmd->n = 0;
	cmd->is_valid = 1;
	cmd->in_fd = 0;
	cmd->out_fd = 1;
	cmd->do_read_stdin = 0;
	while (i < MAX_TAB)
	{
		cmd->s_command[i].nb_args = 0;
		j = 0;
		while (j < MAX_TAB)
		{
			free(cmd->s_command[i].arg[j]);
			cmd->s_command[i].arg[j++] = NULL;
		}
		i++;
	}
}

static void	add_arg(t_simple_command *c, char *arg)
{
	c->arg[(c->nb_args)++] = ft_strdup(arg);
}

static void	fd_gestion(t_command *c, t_token tk[MAX_TAB], int *i)
{
	if (tk[*i].type >= IN_LIMIT && tk[*i].type <= OUT_FILE)
	{
		if (!tk[++(*i)].type)
		{
			ft_printf_error("Unexpected token near : %s\n", tk[*i - 1].content);
			c->is_valid = 0;
			return ;
		}
		fd_in_out(c, tk, i);
		fd_in_limit(c, tk, i);
	}
}

static void	fd_in_out(t_command *c, t_token tk[MAX_TAB], int *i)
{
	if (tk[(*i) - 1].type == IN_FILE)
	{
		if (c->in_fd != 0)
			close(c->in_fd);
		c->in_fd = open(tk[*i].content, O_RDONLY);
		if (c->in_fd < 0)
		{
			ft_printf_error("File don't exists : %s\n", tk[*i].content);
			c->is_valid = 0;
		}
		c->do_read_stdin = 0;
	}
	if (tk[*i - 1].type == OUT_FILE || tk[*i - 1].type == OUT_APPEND)
	{
		if (c->out_fd != 1)
			close(c->out_fd);
		if (tk[*i - 1].type == OUT_FILE)
			c->out_fd = open(tk[*i].content, O_RDWR | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		else
			c->out_fd = open(tk[*i].content, O_RDWR | O_CREAT | O_APPEND,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
}
