/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:14:08 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/11 10:19:57 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_prompt(t_mshell *mshell)
{
	char	*tmp;

	free(mshell->prompt);
	mshell->path = getcwd(NULL, 0);
	if (!mshell->path)
		perror("(☞ ಠ_ಠ)☞ ");
	tmp = ft_strjoin("┌(ikar@minishell)─[", mshell->path);
	mshell->prompt = ft_strjoin(tmp, "]\n└─> ");
	free(tmp);
}

void	ft_setenv(t_mshell *mshell, char *name, char *value)
{
	t_env	**tmp;

	while (*(mshell->env++))
	{
		if (!ft_strcpm(*mshell->env->name, name))
		{
			free(*mshell->env->value);
			*mshell->env->value = ft_strdup(value);
			return ;
		}
	}
	tmp = ft_calloc(env_size + 1, sizeof(t_env *));
	tmp = memmove(tmp, mshell->env, mshell->env_size * sizeof(t_env *));
	free (env);
	mshell->env = tmp;
	mshell->env[mshell->env_size]->name = ft_strdup(name);
	mshell->env[mshell->env_size]->value = ft_strdup(value);
	mshell->env_size++;
}

char	*ft_getenv(t_mshell *mshell, char *name);
{
	while (*(mshell->env++))
		if (!ft_strcpm(*mshell->env->name, name))
			return (*mshell->env->value);
}
