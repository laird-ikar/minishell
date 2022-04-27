/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:01:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/27 07:28:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static void	add_arg(t_simple_command *c, char arg[MAX_TAB]);
static void	fd_gestion(t_command *command, t_token tk[MAX_TAB], int *i, int n);
static void	reset_command(t_command *cmd);

void	ft_parse(t_command *command, t_token token[MAX_TAB])
{
	int	i;
	int	command_number;

	reset_command(command);
	i = 0;
	command_number = 0;
	while (i < MAX_TAB)
	{
		if (token[i].type >= SINGLE_QUOTE_STR && token[i].type <= ENV_VAR)
			add_arg(&command->s_command[command_number], token[i].content);
		fd_gestion(command, token, &i, command_number);
		if (token[i].type == PIPE)
		{
			command_number++;
			if (!token[i + 1].type)
			{
				printf("Unexpected last token : %s\n", token[i].content);
				command->is_valid = 0;
			}
		}
		i++;
	}

	// (void) command;
 	// // COMBAK: lex tester here
	// printf("\n\n");
 	// while ((*token).type)
 	// {
 	// 	printf("type : %d\ncontent : %s\n\n", (*token).type, (*token).content);
 	// 	token++;
 	// }
}

static void	reset_command(t_command *cmd)
{
	int	i;

	i = 0;
	cmd->is_valid = 1;
	while (i < MAX_TAB)
	{
		cmd->s_command[i].nb_args = 0;
		cmd->s_command[i].do_read_stdin = 0;
		cmd->s_command[i].out_fd = 1;
		cmd->s_command[i].in_fd = 0;
		i++;
	}
}

static void	add_arg(t_simple_command *c, char arg[MAX_TAB])
{
	return ;
	(void) c;
	(void) arg;
}

static void	fd_gestion(t_command *c, t_token tk[MAX_TAB], int *i, int n)
{
	if (tk[*i].type >= IN_LIMIT && tk[*i].type <= OUT_APPEND)
	{
		printf("%d %d\n", *i, *i + 1);
		if (!tk[(*i)++].type)
		{
			printf("Unexpected last token : %s\n", tk[*i - 1].content);
			c->is_valid = 0;
		}
		else if (tk[(*i) - 1].type == IN_FILE)
		{
			c->s_command[n].in_fd = open(tk[*i].content, O_RDONLY);
			if (c->s_command[n].in_fd < 0)
			{
				printf("File don't exists : %s\n", tk[*i].content);
				c->is_valid = 0;
			}
		}
		else if (tk[*i - 1].type == OUT_FILE || tk[*i - 1].type == OUT_APPEND)
			c->s_command[n].out_fd = open(tk[*i].content, O_WRONLY | O_CREAT
					| (O_APPEND * (tk[*i - 1].type % 2)));
		else if (tk[*i - 1].type == IN_LIMIT)
		{
			ft_strlcpy(c->s_command[n].eof_marker, tk[*i].content, MAX_TAB);
			c->s_command[n].do_read_stdin = 1;
		}
	}
}
