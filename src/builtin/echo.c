/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:40:00 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/29 09:06:35 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_echo(char *args[MAX_TAB], t_mshell *mshell)
{
	int	i;
	int	to_jump;

	i = 1;
	to_jump = 1;
	if (args[i] && !ft_strcmp(args[i], "-n"))
		to_jump = i++ - 1;
	while (i < MAX_TAB && args[i])
		printf("%s ", args[i++]);
	if (to_jump)
		printf("\n");
	return (0);
	(void) mshell;
}
