/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:37:22 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/28 09:43:55 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(char *args[MAX_TAB], t_mshell *mshell)
{
	ft_printf("%s\n", ft_getenv(mshell, "PWD"));
	return (0);
	(void) args;
}
