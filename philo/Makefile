# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 19:18:30 by stgerard          #+#    #+#              #
#    Updated: 2022/11/29 16:09:44 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = philo.c utils.c time.c init.c philolife.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
			${CC} -pthread ${OBJ} ${CFLAGS} -o ${NAME} -fsanitize=address -g3

clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re