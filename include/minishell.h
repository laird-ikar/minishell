/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:07:22 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/29 07:33:38 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# ifndef T_MSHELL
#  define T_MSHELL

typedef struct s_mshell
{
	int		running;
	char	*prompt;
	char	*line;
	char	*path;
}	t_mshell;
# endif

void	get_prompt(t_mshell *mshell);
void	ft_exit(t_mshell *mshell);

#endif
