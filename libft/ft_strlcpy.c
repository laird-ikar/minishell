/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:24:01 by bguyot            #+#    #+#             */
/*   Updated: 2022/02/23 13:24:06 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_copy(char *dst, const char *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
	{
		ft_copy(dst, src, srclen + 1);
	}
	else if (dstsize != 0)
	{
		ft_copy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

static void	*ft_copy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst != src)
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
