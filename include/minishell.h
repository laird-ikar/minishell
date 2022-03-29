/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:07:22 by bguyot            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/29 07:33:38 by bguyot           ###   ########.fr       */
=======
/*   Updated: 2022/03/29 09:19:13 by bguyot           ###   ########.fr       */
>>>>>>> 31876b4ceff8789e496eba368bd07001592994db
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
<<<<<<< HEAD
void	ft_exit(t_mshell *mshell);
=======
void	ft_exit(void);
void	ft_pwd(void);
>>>>>>> 31876b4ceff8789e496eba368bd07001592994db

#endif
