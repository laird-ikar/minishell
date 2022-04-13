/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:40:00 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/13 08:21:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_echo(char **args, t_mshell *mshell)
{
	char	**split;
	char	**ptr;

	while (*(++args))
	{
		split = ft_split(*args, ' ');
		ptr = split;
		while (*(ptr++))
		{
			ft_putstr_fd(*ptr, 1);
			ft_putchar_fd(' ', 1);
		}
		ptr = split;
		while (*ptr)
		{
			free(*ptr++);
		}
		free(split);
	}
	ft_putchar_fd('\n', 1);
	return (0);
	(void) mshell;
}
