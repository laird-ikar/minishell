/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:14:08 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 07:16:24 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_prompt(t_mshell *mshell)
{
	char	*user;
	char	*path;

	user = ft_getenv(mshell, "USER");
	path = ft_getenv(mshell, "PWD");
	ft_bzero(mshell->prompt, MAX_TAB);
	ft_strlcat(mshell->prompt, "┌(\e[35m", MAX_TAB);
	ft_strlcat(mshell->prompt, user, MAX_TAB);
	ft_strlcat(mshell->prompt, "\e[97m@\e[95mminishell\e[39m)─[\e[91m", MAX_TAB);
	ft_strlcat(mshell->prompt, path, MAX_TAB);
	ft_strlcat(mshell->prompt, "\e[39m]\n└─$ ", MAX_TAB);
}

void	ft_setenv(t_mshell *mshell, char *name, char *value, int type)
{
	int	i;

	i = 0;
	while (i < MAX_TAB && *mshell->env[i].name)
	{
		if (!ft_strcmp(mshell->env[i].name, name))
		{
			ft_strlcpy(mshell->env[i].value, value, MAX_TAB);
			mshell->env[i].is_exported = type;
			return ;
		}
		i++;
	}
	if (i < MAX_TAB)
	{
		ft_strlcpy(mshell->env[i].name, name, MAX_TAB);
		ft_strlcpy(mshell->env[i].value, value, MAX_TAB);
		mshell->env[i].is_exported = type;
		mshell->env_size++;
		return ;
	}
}

char	*ft_getenv(t_mshell *mshell, char *name)
{
	int	i;

	i = 0;
	while (i < MAX_TAB && mshell->env[i].name[0])
	{
		if (!ft_strcmp(mshell->env[i].name, name))
			return (mshell->env[i].value);
		i++;
	}
	return (NULL);
}
