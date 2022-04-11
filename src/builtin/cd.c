/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:19:29 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/11 09:39:24 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

void	ft_cd(char **args, t_mshell *mshell)
{
	char	*tmp;

	tmp = mshell->ft_getenv("PWD");
	if (args[1])
	{
		if (use_path(args[1], mshell))
			return ;
	}
	else
	{
		if (chdir(mshell->ft_getenv("HOME")))
		{
			printf("Error : bad home");
			return ;
		}
	}
	ft_setenv("OLDPWD", tmp);
	ft_setenv("PWD", getcwd(NULL, 0));
}

int	use_path(char *path, t_mshell *mshell)
{
	if (!ft_strcmp(path, "-"))
	{
		if (chdir(mshell->ft_getenv("OLDPWD")))
		{
			printf("Error : bad oldpwd");
			return (1);
		}
	}
	else if (chdir(path))
	{
		printf("Error : bad path");
		return (1);
	}
	return (0);
}
