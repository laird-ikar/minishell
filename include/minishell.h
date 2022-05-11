/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/11 13:43:47 by bguyot           ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

# ifndef MAX_TAB
#  define MAX_TAB 512
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
** VAR=value
*/

enum{
	VOID = 0,
	SINGLE_QUOTE_STR = 1,
	DOUBLE_QUOTE_STR = 2,
	WORD = 3,
	ENV_VAR = 4,
	IN_LIMIT = 5,
	IN_FILE = 6,
	OUT_APPEND = 7,
	OUT_FILE = 8,
	PIPE = 9,
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
	LOCAL = -2,
	UNSETED = -1
};

typedef struct s_env
{
	int		is_exported;
	char	name[MAX_TAB];
	char	value[MAX_TAB];
}	t_env;
# endif

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

# ifndef T_SIMPLE_COMMAND
#  define T_SIMPLE_COMMAND

typedef struct s_simple_command
{
	char	*arg[MAX_TAB];
	int		nb_args;
}	t_simple_command;
# endif

# ifndef T_COMMAND
#  define T_COMMAND

typedef struct s_command
{
	t_simple_command	s_command[MAX_TAB];
	int					in_fd;
	int					out_fd;
	int					is_valid;
	char				eof_marker[MAX_TAB];
	int					do_read_stdin;
	int					n;
}	t_command;
# endif

# ifndef T_MSHELL
#  define T_MSHELL

typedef struct s_mshell
{
	int				running;
	char			prompt[MAX_TAB];
	char			*line;
	char			path[MAX_TAB];
	char			**envtab;
	t_env			env[MAX_TAB];
	int				env_size;
	t_token			token[MAX_TAB];
	t_command		command;
	t_exec			exec;
	struct termios	save;
}	t_mshell;
# endif

void		update_prompt(t_mshell *mshell);
void		ft_execute(t_mshell *mshell, t_command *command);
void		ft_setenv(t_mshell *mshell, char *name, char *value, int type);
void		ft_lex(t_mshell *mshell, t_token token[MAX_TAB], char *line);
void		ft_parse(t_command *command, t_token token[MAX_TAB]);
char		*ft_getenv(t_mshell *mshell, char *name);
void		sig_c(int sig);
void		sig_b(int sig);

#endif
