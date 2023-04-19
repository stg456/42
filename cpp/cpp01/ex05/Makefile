# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 13:41:21 by stgerard          #+#    #+#              #
#    Updated: 2023/04/19 18:19:28 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Harl

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp Harl.cpp \

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
			${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re