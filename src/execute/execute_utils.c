/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:39:28 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/11 07:41:34 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

void	save_stdfd(int stdfd[2])
{
	stdfd[0] = dup(0);
	stdfd[1] = dup(1);
}