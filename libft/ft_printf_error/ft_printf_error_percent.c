/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:40:09 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 08:38:44 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

void	ft_printf_percent(va_list args, int *count)
{
	(void) args;
	ft_putchar_fd('%', 2);
	(*count)++;
}
