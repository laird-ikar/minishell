# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 07:46:58 by bguyot            #+#    #+#              #
#    Updated: 2022/03/29 09:19:31 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

INCLUDE		= ./include/
LIBFT		= ./libft/
ECHO		= ./echo/
CD			= ./cd/
PWD			= ./pwd/
EXPORT		= ./export/
UNSET		= ./unset/
ENV			= ./env/
EXIT		= ./exit/
MAIN		= ./src/

FILES_MAIN	= minishell.c utils.c
FILES_ECHO	=
FILES_CD	=
FILES_PWD	= pwd.c
FILES_EXPORT=
FILES_UNSET	=
FILES_ENV	=
FILES_EXIT	= exit.c
FILES_TEST	= leacks_cheker_ex.c

SRC_MAIN	= $(addprefix $(MAIN),$(FILES_MAIN))
SRC_ECHO	= $(addprefix $(ECHO),$(FILES_ECHO))
SRC_CD		= $(addprefix $(CD),$(FILES_CD))
SRC_PWD		= $(addprefix $(PWD),$(FILES_PWD))
SRC_EXPORT	= $(addprefix $(EXPORT),$(FILES_EXPORT))
SRC_UNSET	= $(addprefix $(UNSET),$(FILES_UNSET))
SRC_ENV		= $(addprefix $(ENV),$(FILES_ENV))
SRC_EXIT	= $(addprefix $(EXIT),$(FILES_EXIT))

SRC			= $(SRC_MAIN) $(SRC_EXIT) $(FILES_TEST)
OBJ			= $(SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
LIBS		= -Llibft -lft -lreadline

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
