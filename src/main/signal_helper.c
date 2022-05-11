/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:29:04 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/11 09:51:22 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_mshell	*g_mshell_ptr;

void	sig_c(int sig)
{
	(void) sig;
	if (kill(g_mshell_ptr->exec.pid, SIGKILL) == -1)
	{
		ft_printf("\n%s", g_mshell_ptr->prompt);
		rl_replace_line(" ", 0);
		rl_redisplay();
	}
	ft_setenv(g_mshell_ptr, "?", "1", LOCAL);
}

void	sig_b(int sig)
{
	if (kill(g_mshell_ptr->exec.pid, SIGKILL) != -1)
		ft_printf("^\\Quit: %d\n", sig);
	ft_setenv(g_mshell_ptr, "?", "0", LOCAL);
}
