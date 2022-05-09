/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:41:12 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 12:40:52 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

static void	if_equals(t_mshell *mshell, char *args, char *ptr);

int	ft_export(char *args[MAX_TAB], t_mshell *mshell)
{
	int		i;
	char	*ptr;

	if (!args[1])
		return (ft_env(args, mshell));
	i = 1;
	while (i < MAX_TAB && args[i])
	{
		ptr = ft_strchr(args[i], '=');
		if (ptr)
			if_equals(mshell, args[i], ptr);
		else
		{
			if (!ft_isalpha(args[i][0]))
				ft_printf_error("sorry, i cannot write on that var : %s\n",
					args[i]);
			else
				ft_setenv(mshell, args[i], "", EXPORTED);
		}
		i++;
	}
	return (0);
}

static void	if_equals(t_mshell *mshell, char *args, char *ptr)
{
	char	tmp[MAX_TAB];

	ft_memmove(tmp, args, ptr - args);
	tmp[ptr - args] = '\0';
	if (!ft_isalpha(tmp[0]))
		ft_printf_error("sorry, i cannot write on that var : %s\n", tmp);
	else
		ft_setenv(mshell, tmp, ptr + 1, EXPORTED);
}
