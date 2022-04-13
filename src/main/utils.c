/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:14:08 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/13 09:20:05 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_prompt(t_mshell *mshell)
{
	getcwd(mshell->path, MAX_TAB);
	*mshell->prompt = 0;
	ft_strlcat(mshell->prompt, "┌(", 2);
	ft_strlcat(mshell->prompt, ft_getenv(mshell, "USER"),
		ft_strlen(ft_getenv(mshell, "USER")));
	ft_strlcat(mshell->prompt, "@minishell)─[", 2);
	ft_strlcat(mshell->prompt, mshell->path, ft_strlen(mshell->path));
	ft_strlcat(mshell->prompt, "]\n└─$", 2);
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
			return ;
		}
		i++;
	}
	if (i < MAX_TAB)
	{
		ft_strlcpy(mshell->env[i].name, name, MAX_TAB);
		ft_strlcpy(mshell->env[i].value, name, MAX_TAB);
		mshell->env[i].is_exported = type;
		return ;
	}
}

char	*ft_getenv(t_mshell *mshell, char *name)
{
	int	i;

	i = 0;
	while (i < MAX_TAB && *mshell->env[i].name)
	{
		if (!ft_strcmp(mshell->env[i].name, name))
			return (mshell->env[i].value);
		i++;
	}
	return (NULL);
}
