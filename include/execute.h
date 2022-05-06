/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:40:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/06 12:12:29 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"
# include "builtin.h"

char	*find_bin(char *bin, t_mshell *mshell);
void	update_envtab(t_mshell *mshell);
void	the_fork(t_exec *exec, t_mshell *mshell, t_command *cmd, int i);
void	update_ret(t_mshell *mshell, int ret);
int		simple_exec(t_simple_command cmd, t_mshell *mshell, t_exec *exec);

#endif
