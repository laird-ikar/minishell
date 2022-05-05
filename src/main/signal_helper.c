/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:29:04 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/05 16:57:57 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_mshell	*g_mshell_ptr;

void	sig_c(int sig)
{
	(void) sig;
	if (kill(g_mshell_ptr->exec.pid, SIGKILL) == -1)
	{
		printf("\n%s", g_mshell_ptr->prompt);
		rl_replace_line(" ", 0);
		rl_redisplay();
	}
}

void	sig_b(int sig)
{
	(void) sig;
	if (kill(g_mshell_ptr->exec.pid, SIGKILL) != -1)
		printf("^\\Quit: 3\n");
}
