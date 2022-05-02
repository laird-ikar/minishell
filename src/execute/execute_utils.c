/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:39:28 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/02 09:19:52 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

void	fd_game(t_exec *exec, t_command *command, int i)
{
	dup2(exec->used_in, 0);
	if (exec->used_in != 0)
		close(exec->used_in);
	if (i == command->n - 1)
		exec->used_out = command->out_fd;
	else
	{
		pipe(exec->pipe_fd);
		exec->used_out = exec->pipe_fd[1];
		exec->used_in = exec->pipe_fd[0];
	}
	dup2(exec->used_out, 1);
	if (exec->used_out != 1)
		close(exec->used_out);
}

char	*find_bin(char *bin, t_mshell *mshell)
{
	int		has_find;
	int		i;
	int		fd;
	char	**split;

	split = ft_split(ft_getenv(mshell, "PATH"), ':');
	//TODO: replace with no malloc split
	has_find = 0;
	i = 0;
	while (!has_find && split[i])
	{
		ft_strlcpy(mshell->path, split[i++], MAX_TAB);
		ft_strlcat(mshell->path, "/", MAX_TAB);
		ft_strlcat(mshell->path, bin, MAX_TAB);
		fd = open(mshell->path, O_RDONLY);
		if (fd >= 0)
			has_find = 1;
		if (fd >= 0)
			close(fd);
	}
	i = 0;
	while (split[i])//TEMP: to remove when no malloc split
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
	}
}
