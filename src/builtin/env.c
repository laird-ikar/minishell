/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:40:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/02 08:42:33 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

int	ft_env(char *args[MAX_TAB], t_mshell *mshell)
{
	int	i;

	if (args[1])
	{
		printf("our env does not support flags nor arguments :(\n");
		return (-1);
	}
	i = 0;
	while (++i < mshell->env_size)
	{
		if (mshell->env[i].is_exported == EXPORTED)
		{
			printf("%s=%s\n", mshell->env[i].name, mshell->env[i].value);
		}
	}
	return (0);
}
