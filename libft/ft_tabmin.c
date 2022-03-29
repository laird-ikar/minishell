/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:16:10 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 12:16:11 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabmin(int *tab, size_t size)
{
	int	res;

	res = 2147483647;
	while (size--)
	{
		if (res < *tab)
			res = *tab;
		tab++;
	}
	return (res);
}
