# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 16:08:20 by stgerard          #+#    #+#              #
#    Updated: 2023/09/22 14:08:01 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp Serializer.cpp \

OBJS = ${SRCS:.cpp=.o}

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
			${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re