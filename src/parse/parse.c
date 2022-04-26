/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:01:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/26 08:10:27 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static void	add_arg(t_simple_command *c, char arg[MAX_TAB]);
static void	fd_gestion(t_command *command, t_token tk[MAX_TAB], int i);

void	ft_parse(t_command *command, t_token token[MAX_TAB])
{
	int	i;
	int	command_number;

	ft_bzero(command, sizeof (t_command));
	command->is_valid = 1;
	command->out_fd = 1;
	i = 0;
	command_number = 0;
	while (i < MAX_TAB)
	{
		if (token[i].type >= SINGLE_QUOTE_STR && token[i].type <= ENV_VAR)
			add_arg(&command->s_command[command_number], token[i].content);
		fd_gestion(command, token, i);
		i++;
	}
}

static void	add_arg(t_simple_command *c, char arg[MAX_TAB])
{
	return ;
	(void) c;
	(void) arg;
}

static void	fd_gestion(t_command *command, t_token tk[MAX_TAB], int i)
{
	if (tk[i].type >= IN_LIMIT && tk[i].type <= OUT_APPEND)
	{
		if (!tk[i++].type)
		{
			printf("Unexpected last token : %s\n", tk[i - 1].content);
			command->is_valid = 0;
		}
		else if (tk[i - 1].type == IN_FILE)
		{
			command->in_fd = open(tk[i].content, O_RDONLY);
			if (command->in_fd < 0)
			{
				printf("File don't exists : %s\n", tk[i].content);
				command->is_valid = 0;
			}
		}
		else if (tk[i - 1].type == OUT_FILE || tk[i - 1].type == OUT_APPEND)
			command->out_fd = open(tk[i].content, O_WRONLY | O_CREAT
					| (O_APPEND * (tk[i - 1].type % 2)));
		else if (tk[i - 1].type == IN_LIMIT)
		{
			ft_strlcpy(command->eof_marker, tk[i].content, MAX_TAB);
			command->do_read_stdin = 1;
		}
	}
}
