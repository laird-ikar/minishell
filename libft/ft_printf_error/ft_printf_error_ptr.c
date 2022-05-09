/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:39:59 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 08:41:19 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

void	ft_printf_ptr(va_list args, int *count)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("0x0", 2);
		(*count) += 3;
	}
	else
	{
		str = ft_ultoa_base((unsigned long) ptr, "0123456789abcdef");
		ft_putstr_fd("0x", 2);
		ft_putstr_fd(str, 2);
		*count += (2 + ft_strlen(str));
		free(str);
	}
}
