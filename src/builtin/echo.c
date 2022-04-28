/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:40:00 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/28 07:43:05 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_echo(char args[MAX_TAB][MAX_TAB], t_mshell *mshell)
{
	while (*(++args))
		printf("%s ", *args);
	printf("\n");
	return (0);
	(void) mshell;
}
