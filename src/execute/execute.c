/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:33:43 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/11 09:46:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

static void	pid_game(t_exec *exec, t_mshell *mshell, t_command *cmd, int i);
static int	is_builtin(char arg[MAX_TAB]);

typedef int	(*t_builtin)(char *args[MAX_TAB], t_mshell *mshell);

void	ft_execute(t_mshell *mshell, t_command *command)
{
	int	i;

	if (!command->is_valid)
		return ;
	i = -1;
	mshell->exec.saved_in = dup(0);
	mshell->exec.saved_out = dup(1);
	mshell->exec.used_in = command->in_fd;
	while (++i < command->n)
		pid_game(&mshell->exec, mshell, command, i);
	dup2(mshell->exec.saved_in, STDIN_FILENO);
	dup2(mshell->exec.saved_out, STDOUT_FILENO);
	close(mshell->exec.saved_in);
	close(mshell->exec.saved_out);
	close(mshell->exec.pipe_fd[0]);
	close(mshell->exec.pipe_fd[1]);
}

static void	pid_game(t_exec *exec, t_mshell *mshell, t_command *cmd, int i)
{
	pipe(exec->pipe_fd);
	if (is_builtin(cmd->s_command[i].arg[0]) == -1)
		return ;
	if (is_builtin(cmd->s_command[i].arg[0]) >= 0)
	{
		dup2(exec->used_in, STDIN_FILENO);
		if (i != cmd->n - 1)
			dup2(exec->pipe_fd[1], STDOUT_FILENO);
		else
			dup2(cmd->out_fd, STDOUT_FILENO);
		exec->used_in = exec->pipe_fd[0];
		exec->ret = simple_exec(cmd->s_command[i], mshell, exec);
		close(exec->pipe_fd[1]);
		update_ret(mshell, exec->ret);
		dup2(exec->saved_in, STDIN_FILENO);
		dup2(exec->saved_out, STDOUT_FILENO);
		return ;
	}
	the_fork(exec, mshell, cmd, i);
}

void	update_ret(t_mshell *mshell, int ret)
{
	char	*tmp;

	tmp = ft_itoa(ret);
	ft_setenv(mshell, "?", tmp, LOCAL);
	free (tmp);
}

int	simple_exec(t_simple_command cmd, t_mshell *mshell, t_exec *exec)
{
	int					ret;
	int					i;
	char				*path;
	static t_builtin	builtin[] = {ft_cd, ft_echo, ft_env, ft_exit, ft_export,
		ft_pwd, ft_unset};

	ret = is_builtin(cmd.arg[0]);
	if (ret >= 0)
		return ((builtin[ret])(cmd.arg, mshell));
	path = find_bin(cmd.arg[0], mshell);
	ret = 127;
	close(exec->pipe_fd[0]);
	if (path)
	{
		update_envtab(mshell);
		ret = execve(path, cmd.arg, mshell->envtab);
		i = 0;
	}
	else
		ft_printf_error("%s not found\n", cmd.arg[0]);
	return (ret);
}

static int	is_builtin(char arg[MAX_TAB])
{
	if (!ft_strcmp(arg, "cd"))
		return (0);
	if (!ft_strcmp(arg, "echo"))
		return (1);
	if (!ft_strcmp(arg, "env"))
		return (2);
	if (!ft_strcmp(arg, "exit"))
		return (3);
	if (!ft_strcmp(arg, "export"))
		return (4);
	if (!ft_strcmp(arg, "pwd"))
		return (5);
	if (!ft_strcmp(arg, "unset"))
		return (6);
	if (!ft_strcmp(arg, "minishell") || !ft_strcmp(arg, "./minishell"))
		return (-1 + 0 * ft_printf_error(
				"\e[96mI should drink water before incepting my shell...\
\e[39m\n"));
	return (-42);
}
