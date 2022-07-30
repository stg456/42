# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 19:18:30 by stgerard          #+#    #+#              #
#    Updated: 2022/07/30 15:30:27 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -lpthread -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -f

SRC = plilo.c utils.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
			${CC} -o ${NAME} ${OBJ} ${CFLAGS}

.c.o:
				${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re