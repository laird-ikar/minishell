/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/08 13:23:12 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# ifndef T_TOKEN
#  define T_TOKEN

typedef struct s_token
{
	int		type;
	char	*content;
}	t_token;
# endif

# ifndef T_ENV
#  define T_ENV

typedef struct s_env
{
	char	*name;
	char	*value;
}	t_env;
# endif

# ifndef T_COMMAND
#  define T_COMMAND

typedef struct s_command
{
}	t_command;
# endif

# ifndef T_MSHELL
#  define T_MSHELL

typedef struct s_mshell
{
	int			running;
	char		*prompt;
	char		*line;
	char		*path;
	t_env		**env_vars;
	t_token		**tokens;
	t_command	*command;
}	t_mshell;
# endif

void		update_prompt(t_mshell *mshell);
void		ft_execute(t_command *command);
t_token		**ft_lex(char *line);
t_command	*ft_parse(t_token **tokens);

#endif
