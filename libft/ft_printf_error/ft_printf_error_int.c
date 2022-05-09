/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:39:51 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 08:41:17 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

void	ft_printf_int(va_list args, int *count)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return ;
	ft_putstr_fd(str, 2);
	*count += ft_strlen(str);
	free(str);
}
