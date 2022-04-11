# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 07:46:58 by bguyot            #+#    #+#              #
#    Updated: 2022/04/08 10:37:38 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

INCLUDE			= ./include/
LIBFT			= ./libft/
MAIN			= ./src/main/
BUILTIN			= ./src/builtin/
LEX				= ./src/lex/
PARSE			= ./src/parse/
EXEC			= ./src/EXEC/

FILES_MAIN		= minishell.c utils.c
FILES_BUILTIN	= cd.c echo.c env.c exit.c export.c pwd.c unset.c
FILES_LEX		=
FILES_PARSE		=
FILES_EXEC	=

SRC_MAIN		= $(addprefix $(MAIN),$(FILES_MAIN))
SRC_BUILTIN		= $(addprefix $(BUILTIN),$(FILES_BUILTIN))
SRC_LEX			= $(addprefix $(LEX),$(FILES_LEX))
SRC_PARSE		= $(addprefix $(PARSE),$(FILES_PARSE))
SRC_EXEC		= $(addprefix $(EXEC),$(FILES_EXEC))

SRC				= $(SRC_MAIN) $(SRC_BUILTIN) $(SRC_LEX) $(SRC_PARSE) $(SRC_EXEC)
OBJ				= $(SRC:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
LIBS			= -Llibft -lft -lreadline

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBS) $(OBJ)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
