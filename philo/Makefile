# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 19:18:30 by stgerard          #+#    #+#              #
#    Updated: 2022/07/30 16:26:18 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LFLAGS = -pthread

RM = rm -f

SRC = plilo.c utils.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
			${CC} ${OBJ} ${CFLAGS} $(LFLAGS) -o ${NAME}

.c.o:
				${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re