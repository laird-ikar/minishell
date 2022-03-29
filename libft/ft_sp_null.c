/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:17:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/29 09:20:58 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_sp_null(char *src)
{
  if (!src)
    return (1);
  while (*src)
  {
    if (!ft_isspace(*src))
      return (0);
    src++;
  }
  return (1);
}