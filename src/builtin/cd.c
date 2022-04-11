/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:19:29 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/11 10:03:47 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

static int	use_path(char *path, t_mshell *mshell);

void	ft_cd(char **args, t_mshell *mshell)
{
	char	*tmp;

	tmp = ft_getenv(mshell, "PWD");
	if (args[1])
	{
		if (use_path(args[1], mshell))
			return ;
	}
	else
	{
		if (chdir(ft_getenv(mshell, "HOME")))
		{
			printf("Error : bad home");
			return ;
		}
	}
	ft_setenv(mshell, "OLDPWD", tmp);
	ft_setenv(mshell, "PWD", getcwd(NULL, 0));
}

static int	use_path(char *path, t_mshell *mshell)
{
	if (!ft_strcmp(path, "-"))
	{
		if (chdir(ft_getenv(mshell, "OLDPWD")))
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
