/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:14:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 12:14:19 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcontain(char **src, char *tofind)
{
	while (*src)
	{
		if (!ft_strcmp(*src, tofind))
			return (1);
		src++;
	}
	return (0);
}
