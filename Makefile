# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 07:46:58 by bguyot            #+#    #+#              #
#    Updated: 2022/04/12 10:43:48 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

INCLUDE			= ./include/
LIBFT			= ./libft/
MAIN			= ./src/main/
BUILTIN			= ./src/builtin/
LEX				= ./src/lex/
PARSE			= ./src/parse/
EXEC			= ./src/execute/

FILES_MAIN		= minishell.c utils.c
FILES_BUILTIN	= cd.c echo.c env.c exit.c export.c pwd.c unset.c
FILES_LEX		= lex.c
FILES_PARSE		= parse.c
FILES_EXEC		= execute.c execute_utils.c

SRC_MAIN		= $(addprefix $(MAIN),$(FILES_MAIN))
SRC_BUILTIN		= $(addprefix $(BUILTIN),$(FILES_BUILTIN))
SRC_LEX			= $(addprefix $(LEX),$(FILES_LEX))
SRC_PARSE		= $(addprefix $(PARSE),$(FILES_PARSE))
SRC_EXEC		= $(addprefix $(EXEC),$(FILES_EXEC))

SRC				= $(SRC_MAIN) $(SRC_BUILTIN) $(SRC_LEX) $(SRC_PARSE) $(SRC_EXEC)
OBJ				= $(SRC:.c=.o)
SRC_TEST		= $(SRC_BUILTIN) $(SRC_LEX) $(SRC_PARSE) $(SRC_EXEC)			\
$(MAIN)execute_utils.c
OBJ_TEST		= $(SRC_TEST:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g
LDLIBS			= -Llibft -lft -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
CPPFLAGS		= -I/Users/$(USER)/.brew/opt/readline/include -Iinclude -Ilibft

RM				= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(LDLIBS) $(OBJ)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

update_lib: fclean
	$(RM) $(LIBFT)
	git clone git@github.com:laird-ikar/libft.git $(LIBFT)
	$(RM) $(LIBFT).git $(LIBFT).gitignore

.PHONY:	all clean fclean re
