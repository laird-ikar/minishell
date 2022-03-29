/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:16:15 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 12:16:16 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabmax(int *tab, size_t size)
{
	int	res;

	res = -2147483648;
	while (size--)
	{
		if (res > *tab)
			res = *tab;
		tab++;
	}
	return (res);
}
