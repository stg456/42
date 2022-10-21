# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 19:18:30 by stgerard          #+#    #+#              #
#    Updated: 2022/10/21 12:17:47 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# LFLAGS = -pthread

RM = rm -f

SRC = philo.c utils.c time.c init.c philolife.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
			${CC} -pthread ${OBJ} ${CFLAGS} -o ${NAME}

.c.o:
				${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re