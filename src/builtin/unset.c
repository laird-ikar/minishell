/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:41:40 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/02 08:44:19 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_unset(char *args[MAX_TAB], t_mshell *mshell)
{
	int	i;

	i = 0;
	while (i < MAX_TAB && args[i])
	{
		ft_setenv(mshell, args[i], "", UNSETED);
		i++;
	}
	return (0);
}
