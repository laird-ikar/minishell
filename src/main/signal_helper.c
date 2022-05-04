/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:29:04 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/04 09:18:01 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_mshell	*mshell_ptr;

void	sig_c(int sig)
{
	(void) sig;
	if (kill(mshell_ptr->exec.pid, SIGKILL) == -1)
		printf("\n%s", mshell_ptr->prompt);
}

void	sig_b(int sig)
{
	rl_redisplay ();
	(void) sig;
}
