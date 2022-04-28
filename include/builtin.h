/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 08:55:54 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/28 09:43:22 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int	ft_cd(char *args[MAX_TAB], t_mshell *mshell);
int	ft_echo(char *args[MAX_TAB], t_mshell *mshell);
int	ft_env(char *args[MAX_TAB], t_mshell *mshell);
int	ft_exit(char *args[MAX_TAB], t_mshell *mshell);
int	ft_export(char *args[MAX_TAB], t_mshell *mshell);
int	ft_pwd(char *args[MAX_TAB], t_mshell *mshell);
int	ft_unset(char *args[MAX_TAB], t_mshell *mshell);

#endif
