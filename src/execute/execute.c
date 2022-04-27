/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:33:43 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/27 09:42:29 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

static void	pid_game(t_exec *exec, t_mshell *mshell, t_command *cmd, int i);
static int	simple_exec(t_simple_command cmd, t_mshell *mshell);

typedef int (*)(char **args, t_mshell *mshell)	t_builtin;

t_builtin										g_builtin[]
	= {cd, echo, env, exit, export, pwd, unset};

void	ft_execute(t_mshell *mshell, t_command *command)
{
	int		i;
	t_exec	exec;

	if (!command->is_valid)
		return ;
	i = -1;
	exec.saved_in = dup(0);
	exec.saved_out = dup(1);
	exec.used_in = command->in_fd;
	// TODO: implement << input
	while (++i < command->n)
	{
		fd_game(&exec, command, i);
		pid_game(&exec, mshell, command, i);
	}
	dup2(exec.saved_in, 0);
	dup2(exec.saved_out, 1);
}

static void	pid_game(t_exec *exec, t_mshell *mshell, t_command *cmd, int i)
{
	char	*tmp;

	exec->pid = fork();
	if (!exec->pid)
	{
		exec->ret = simple_exec(cmd->s_command[i], mshell);
		exit(exec->ret);
	}
	else
	{
		waitpid(exec->pid, &exec->ret, 0);
		tmp = ft_itoa(exec->ret);
		ft_setenv(mshell, "?", tmp, LOCAL);
		free (tmp);
	}
}

static int	simple_exec(t_simple_command cmd, t_mshell *mshell)
{
	int	ret;

	ret = is_builtin(cmd.arg[0]);
	if (ret >= 0)
		(g_builtin[ret])(cmd.arg, mshell);
}
