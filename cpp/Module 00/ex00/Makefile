# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:18:12 by stgerard          #+#    #+#              #
#    Updated: 2023/01/15 16:23:10 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRCS = megaphone.cpp

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
			${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re