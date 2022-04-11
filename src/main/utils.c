/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:14:08 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/08 08:52:05 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_prompt(t_mshell *mshell)
{
	char	*tmp;

	free(mshell->prompt);
	mshell->path = getcwd(NULL, 0);
	if (!mshell->path)
		perror("(☞ ಠ_ಠ)☞ ");
	tmp = ft_strjoin("┌(ikar@minishell)─[", mshell->path);
	mshell->prompt = ft_strjoin(tmp, "]\n└─> ");
	free(tmp);
}
