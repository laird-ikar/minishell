/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:40:00 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/11 10:23:05 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

void	ft_print_split(char **split, t_mshell mshell);

void	ft_echo(char **args, t_mshell *mshell)
{
	char	**split;
	char	**ptr;

	while (*(++args))
	{
		split = ft_split(*args, ' ');
		ptr = split;
		while (*(split++))
		{
			ft_print_split(split, mshell);
		}
		while (*ptr)
		{
			free(*ptr++);
		}
		free(ptr);
	}
}

void	ft_print_split(char **split, t_mshell mshell)
{
	if (!ft_strchr(*split, '$'))
		ft_putstr_fd(*split, 0);
	else
	{
		while (*((*split)++))
		{
			if (**split == '$')
			{
				ft_putstr_fd(ft_getenv(mshell, (*split)++), 0);
				break ;
			}
			ft_putchar_fd(**split, 0);
		}
	}
	ft_putchar_fd(' ', 0);
}
