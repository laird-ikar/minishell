/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:19:29 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/04 07:43:46 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

static int	use_path(char *path, t_mshell *mshell);

int	ft_cd(char *args[MAX_TAB], t_mshell *mshell)
{
	char	*tmp;

	tmp = ft_getenv(mshell, "PWD");
	if (args[1] && ft_strcmp(args[1], "~"))
	{
		if (use_path(args[1], mshell))
			return (1);
	}
	else
	{
		if (chdir(ft_getenv(mshell, "HOME")))
		{
			printf("Error : bad home\n");
			return (1);
		}
	}
	ft_setenv(mshell, "OLDPWD", tmp, EXPORTED);
	ft_setenv(mshell, "PWD", getcwd(NULL, 0), EXPORTED);
	return (0);
}

static int	use_path(char *path, t_mshell *mshell)
{
	if (!ft_strcmp(path, "-"))
	{
		if (chdir(ft_getenv(mshell, "OLDPWD\n")))
		{
			printf("Error : bad oldpwd\n");
			return (1);
		}
	}
	else if (chdir(path))
	{
		printf("Error : bad path\n");
		return (1);
	}
	return (0);
}
