/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:41:12 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/29 09:24:55 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_export(char *args[MAX_TAB], t_mshell *mshell)
{
	int		i;
	char	*ptr;
	char	tmp[MAX_TAB];

	if (!args[1])
		return (ft_env(args, mshell));
	i = 1;
	while (i < MAX_TAB && args[i])
	{
		ptr = ft_strchr(args[i], '=');
		if (ptr)
		{
			ft_memmove(tmp, args[i], ptr - args[i]);
			tmp[ptr - args[i]] = '\0';
			ft_setenv(mshell, tmp, ptr + 1, EXPORTED);
		}
		else
			ft_setenv(mshell, args[i], "", EXPORTED);
		i++;
	}
	return (0);
}
