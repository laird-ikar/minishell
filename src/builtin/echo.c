/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:40:00 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/25 08:56:16 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_echo(char **args, t_mshell *mshell)
{
	char	**split;
	char	**ptr;

	while (*(++args))
		printf("%s ", *args);
	printf("\n");
	return (0);
	(void) mshell;
}
