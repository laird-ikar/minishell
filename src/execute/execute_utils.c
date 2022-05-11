/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:39:28 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/11 09:43:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

char	*find_bin(char *bin, t_mshell *mshell)
{
	int		has_find;
	int		i;
	int		fd;
	char	**split;

	split = ft_split(ft_getenv(mshell, "PATH"), ':');
	has_find = 0;
	i = 0;
	while (!has_find && split[i])
	{
		ft_strlcpy(mshell->path, split[i++], MAX_TAB);
		ft_strlcat(mshell->path, "/", MAX_TAB);
		ft_strlcat(mshell->path, bin, MAX_TAB);
		fd = access(mshell->path, X_OK);
		if (!fd)
			has_find = 1;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	if (has_find)
		return (mshell->path);
	return (NULL);
}

void	update_envtab(t_mshell *mshell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MAX_TAB && j < MAX_TAB && mshell->env[i].is_exported)
	{
		if (mshell->env[i].is_exported == EXPORTED)
		{
			ft_strlcpy(mshell->envtab[j], mshell->env[i].name, MAX_TAB);
			ft_strlcat(mshell->envtab[j], "=", MAX_TAB);
			ft_strlcat(mshell->envtab[j], mshell->env[i].value, MAX_TAB);
			j++;
		}
		i++;
	}
	ft_strlcpy(mshell->envtab[j], "", MAX_TAB);
}

void	the_fork(t_exec *exec, t_mshell *mshell, t_command *cmd, int i)
{
	exec->pid = fork();
	if (!exec->pid)
	{
		dup2(exec->used_in, STDIN_FILENO);
		if (i != cmd->n - 1)
			dup2(exec->pipe_fd[1], STDOUT_FILENO);
		else
			dup2(cmd->out_fd, STDOUT_FILENO);
		exit(simple_exec(cmd->s_command[i], mshell, exec));
	}
	else
	{
		close(exec->pipe_fd[1]);
		exec->used_in = exec->pipe_fd[0];
		waitpid(exec->pid, &exec->ret, 0);
		if (WIFEXITED(exec->ret))
			update_ret(mshell, WEXITSTATUS(exec->ret));
		else
			ft_setenv(mshell, "?", "127", LOCAL);
	}
}
