/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:26:54 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/10 14:27:15 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmaxint(t_list *lst)
{
	int	max;

	max = -2147483648;
	while (lst)
	{
		if (max < *(int *)lst->cont)
		{
			max = *(int *)lst->cont;
		}
		lst = lst->nx;
	}
	return (max);
}
