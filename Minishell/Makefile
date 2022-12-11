# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 19:06:31 by stgerard          #+#    #+#              #
#    Updated: 2022/12/11 16:13:46 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRC = minishell.c \
../libft/ft_putstr.c ../libft/ft_split.c ../libft/ft_strlen.c 

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
			${CC} -pthread ${OBJ} ${CFLAGS} -o ${NAME}

clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re