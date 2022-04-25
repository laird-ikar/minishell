/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/25 07:30:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>

# ifndef MAX_TAB
#  define MAX_TAB 1024
# endif

# ifndef T_TOKEN
#  define T_TOKEN

/* in order :
** empty token
** str entre '
** str entre "
** any word (no space)
** |
** <<
** <
** >
** >>
** envvar
*/

enum{
	VOID = 0,
	SINGLE_QUOTE_STR = 1,
	DOUBLE_QUOTE_STR = 2,
	WORD = 3,
	PIPE = 4,
	IN_LIMIT = 5,
	IN_FILE = 6,
	OUT_FILE = 7,
	OUT_APPEND = 8,
	ENV_VAR = 9
};

typedef struct s_token
{
	int		type;
	char	content[MAX_TAB];
}	t_token;
# endif

# ifndef T_ENV
#  define T_ENV

/*	is_exported :
**		EXPORTED :	was set by export, must be in the env and must be interpreted
**		LOCAL :		must be interpreted, but must not be in the env
**
**	name : a string that represente the name
**	value : a string that represente the variable
**
**	set :	name=value
**	get :	$(name) -> value
*/

enum{
	EXPORTED = 1,
	LOCAL = 0
};

typedef struct s_env
{
	int		is_exported;
	char	name[MAX_TAB];
	char	value[MAX_TAB];
}	t_env;
# endif

# ifndef T_SIMPLE_COMMAND
#  define T_SIMPLE_COMMAND

typedef struct s_simple_command
{
	char	args[MAX_TAB][MAX_TAB];
}	t_simple_command;
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
	char		prompt[MAX_TAB];
	char		*line;
	char		path[MAX_TAB];
	t_env		env[MAX_TAB];
	size_t		env_size;
	t_token		token[MAX_TAB];
	t_command	command;
}	t_mshell;
# endif

void		update_prompt(t_mshell *mshell);
void		ft_execute(t_command *command);
void		ft_setenv(t_mshell *mshell, char *name, char *value, int type);
void		ft_lex(t_mshell *mshell, t_token token[MAX_TAB], char *line);
void		ft_parse(t_command *command, t_token token[MAX_TAB]);
char		*ft_getenv(t_mshell *mshell, char *name);

#endif
