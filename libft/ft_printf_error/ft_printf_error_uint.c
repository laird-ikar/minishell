/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error_uint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:40:01 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 08:41:19 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

void	ft_printf_uint(va_list args, int *count)
{
	char	*str;

	str = ft_utoa(va_arg(args, unsigned int));
	if (!str)
		return ;
	ft_putstr_fd(str, 2);
	*count += ft_strlen(str);
	free(str);
}
