/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error_xint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:39:55 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 08:41:20 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

void	ft_printf_xint(va_list args, int *count)
{
	unsigned int	a;
	char			*str;

	a = (unsigned int) va_arg(args, int);
	str = ft_utoa_base(a, "0123456789abcdef");
	ft_putstr_fd(str, 2);
	*count += ft_strlen(str);
	free(str);
}
