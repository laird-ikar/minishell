/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:39:28 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/28 08:17:38 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

void	fd_game(t_exec *exec, t_command *command, int i)
{
	if (exec->used_in != 0)
	{
		dup2(exec->used_in, 0);
		close(exec->used_in);
	}
	if (i == command->n - 1)
		exec->used_out = command->out_fd;
	else
	{
		pipe(exec->pipe_fd);
		exec->used_out = exec->pipe_fd[1];
		exec->used_in = exec->pipe_fd[0];
	}
	if (exec->used_out!= 1)
	{
		dup2(exec->used_out, 1);
		close(exec->used_out);
	}
}
