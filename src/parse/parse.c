/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:01:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/28 07:28:17 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static void	add_arg(t_simple_command *c, char arg[MAX_TAB]);
static void	fd_gestion(t_command *command, t_token tk[MAX_TAB], int *i);
static void	reset_command(t_command *cmd);

void	ft_parse(t_command *command, t_token token[MAX_TAB])
{
	int	i;

	reset_command(command);
	i = 0;
	command->n = 0;
	while (i < MAX_TAB && token[i].type)
	{
		if (token[i].type >= SINGLE_QUOTE_STR && token[i].type <= ENV_VAR)
			add_arg(&command->s_command[command->n], token[i].content);
		fd_gestion(command, token, &i);
		if (token[i].type == PIPE)
		{
			command->n++;
			if (!token[i + 1].type)
			{
				printf("Unexpected last token : %s\n", token[i].content);
				command->is_valid = 0;
			}
		}
		i++;
	}
}

static void	reset_command(t_command *cmd)
{
	int	i;

	i = 0;
	cmd->n = 0;
	cmd->is_valid = 1;
	cmd->in_fd = 0;
	cmd->out_fd = 1;
	cmd->do_read_stdin = 0;
	while (i < MAX_TAB)
	{
		cmd->s_command[i].nb_args = 0;
		i++;
	}
}

static void	add_arg(t_simple_command *c, char arg[MAX_TAB])
{
	ft_strlcpy(c->arg[(c->nb_args)++], arg, MAX_TAB);
}

static void	fd_gestion(t_command *c, t_token tk[MAX_TAB], int *i)
{
	if (tk[*i].type >= IN_LIMIT && tk[*i].type <= OUT_FILE)
	{
		if (!tk[(*i)++].type)
		{
			printf("Unexpected last token : %s\n", tk[*i - 1].content);
			c->is_valid = 0;
		}
		else if (tk[(*i) - 1].type == IN_FILE)
		{
			if (c->in_fd != 0)
				close(c->in_fd);
			c->in_fd = open(tk[*i].content, O_RDONLY);
			if (c->in_fd < 0)
			{
				printf("File don't exists : %s\n", tk[*i].content);
				c->is_valid = 0;
			}
			c->do_read_stdin = 0;
		}
		else if (tk[*i - 1].type == OUT_FILE || tk[*i - 1].type == OUT_APPEND)
		{
			if (c->out_fd != 1)
				close(c->out_fd);
			if (tk[*i - 1].type == OUT_FILE)
				c->out_fd = open(tk[*i].content, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			else
				c->out_fd = open(tk[*i].content, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		}
		else if (tk[*i - 1].type == IN_LIMIT)
		{
			ft_strlcpy(c->eof_marker, tk[*i].content, MAX_TAB);
			c->do_read_stdin = 1;
		}
	}
}
