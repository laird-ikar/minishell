/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:55:32 by bguyot           #+#    #+#             */
/*   Updated: 2022/02/23 13:18:27 by bguyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**res;
	t_list	*tmp;

	res = malloc(sizeof (t_list *));
	if (!res)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->cont));
		ft_lstadd_back(res, tmp);
		ft_lstdelone(tmp, del);
		lst = lst->nx;
	}
	return (*res);
}
