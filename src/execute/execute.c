/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:33:43 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/26 09:30:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

void	save_stdfd(int stdfd[2]);

void	ft_execute(t_command *command)
{
	int i = -1;
	while (command->s_command[++i].nb_args)
	{
		int j = -1;
		while (++j < command->s_command[i].nb_args)
		{
			printf("%s ", command->s_command[i].arg[j]);
		}
		printf("in fd : %d\n", command->s_command[i].in_fd);
		printf("out fd : %d\n", command->s_command[i].out_fd);
		printf("do_read_stdin : %d (stops at : %s)\n", command->s_command[i].do_read_stdin,
			command->s_command[i].eof_marker);
		printf("\n\n|\n\n");
	}
	printf("is valid : %d\n", command->is_valid);
}
