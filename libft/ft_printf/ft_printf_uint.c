/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:40:01 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/17 07:51:04 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_uint(va_list args, int *count)
{
	char	*str;

	str = ft_utoa(va_arg(args, unsigned int));
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
