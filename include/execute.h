/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:40:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/03 08:20:32 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"
# include "builtin.h"

# ifndef T_EXEC
#  define T_EXEC

typedef struct s_exec
{
	int	saved_in;
	int	saved_out;
	int	used_in;
	int	used_out;
	int	pipe_fd[2];
	int	pid;
	int	ret;
}	t_exec;
# endif

char	*find_bin(char *bin, t_mshell *mshell);
void	update_envtab(t_mshell *mshell);

#endif
