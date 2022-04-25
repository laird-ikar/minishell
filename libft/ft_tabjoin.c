/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 07:19:25 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/25 07:33:33 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabjoin(char **tab, char *sep)
{
	char	*res;
	char	*tmp;

	res = NULL;
	tmp = NULL;
	while (*tab && *(tab + 1))
	{
		tmp = ft_strjoin(res, *tab);
		free (res);
		res = tmp;
		tmp = ft_strjoin(res, sep);
		free (res);
		res = tmp;
		tab++;
	}
	tmp = ft_strjoin(res, *tab);
	free (res);
	res = tmp;
	return (res);
}
