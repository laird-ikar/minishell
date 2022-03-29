/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:24:12 by bguyot            #+#    #+#             */
/*   Updated: 2022/02/23 13:24:17 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && ((unsigned char *) s1)[i] && ((unsigned char *) s2)[i]
		&& ((unsigned char *) s1)[i] == ((unsigned char *) s2)[i])
	{
		i++;
	}
	if (n)
		return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
	return (0);
}
