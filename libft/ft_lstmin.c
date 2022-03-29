/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:26:54 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/10 14:43:33 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmaxint(t_list *lst)
{
	int	min;

	min = 2147483647;
	while (lst)
	{
		if (min > *(int *)lst->cont)
		{
			min = *(int *)lst->cont;
		}
		lst = lst->nx;
	}
	return (min);
}
