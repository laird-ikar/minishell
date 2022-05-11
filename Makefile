# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 07:46:58 by bguyot            #+#    #+#              #
#    Updated: 2022/05/11 13:43:10 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

INCLUDE			=	./include/
LIBFT			=	./libft/libft.a
LIBFTDIR		=	./libft/
MAIN			=	./src/main/
BUILTIN			=	./src/builtin/
LEX				=	./src/lex/
PARSE			=	./src/parse/
EXEC			=	./src/execute/

FILES_MAIN		=	minishell.c utils.c signal_helper.c
FILES_BUILTIN	=	cd.c echo.c env.c exit.c export.c pwd.c unset.c
FILES_LEX		=	lex.c lex_utils.c
FILES_PARSE		=	parse.c parse_utils.c
FILES_EXEC		=	execute.c execute_utils.c

SRC_MAIN		=	$(addprefix $(MAIN),$(FILES_MAIN))
SRC_BUILTIN		=	$(addprefix $(BUILTIN),$(FILES_BUILTIN))
SRC_LEX			=	$(addprefix $(LEX),$(FILES_LEX))
SRC_PARSE		=	$(addprefix $(PARSE),$(FILES_PARSE))
SRC_EXEC		=	$(addprefix $(EXEC),$(FILES_EXEC))

SRC				=	$(SRC_MAIN) $(SRC_BUILTIN) $(SRC_LEX) $(SRC_PARSE)			\
$(SRC_EXEC)
OBJ				=	$(SRC:.c=.o)
SRC_TEST		=	$(SRC_BUILTIN) $(SRC_LEX) $(SRC_PARSE) $(SRC_EXEC)			\
					$(MAIN)execute_utils.c
OBJ_TEST		=	$(SRC_TEST:.c=.o)

CC				=	@gcc
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g
LDLIBS			=	-Llibft -lft												\
					-lreadline -lcurses -L/Users/$(USER)/.brew/opt/readline/lib
CPPFLAGS		=	-I/usr/local/opt/readline/include							\
					-I/Users/$(USER)/.brew/opt/readline/include -Iinclude		\
					-Ilibft

RM				=	@rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(LDLIBS) $(OBJ)
	@printf "\e[36m\tCompilation \t[ ✓ ]\n\e[39m"

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(RM) $(OBJ)
	@printf "\e[31m\tClean \t\t[ ✓ ]\n\e[39m"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(RM) $(NAME)
	@printf "\e[35;5;161m\tBinary Clean \t[ ✓ ]\n\e[39m"

re: fclean all

update_lib: fclean
	@$(RM) $(LIBFTDIR)
	@git clone -q git@github.com:laird-ikar/libft.git $(LIBFTDIR)
	@$(RM) $(LIBFTDIR).git $(LIBFTDIR).gitignore
	@printf "\e[93m\tLibft Clone \t[ ✓ ]\n\e[39m"

.PHONY:	all clean fclean re
