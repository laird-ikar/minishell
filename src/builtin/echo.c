/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:40:00 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/11 07:47:37 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_echo(char *args[MAX_TAB], t_mshell *mshell)
{
	int	i;
	int	to_jump;

	i = 1;
	to_jump = 1;
	while (i < MAX_TAB && args[i] && i + 1 < MAX_TAB)
	{
		if (args[i] && !ft_strcmp(args[i], "-n"))
			to_jump = 0;
		else if (args[i + 1])
			ft_printf("%s ", args[i]);
		else
			ft_printf("%s", args[i]);
		i++;
	}
	if (to_jump)
		ft_printf("\n");
	return (0);
	(void) mshell;
}
