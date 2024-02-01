# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 16:37:16 by stgerard          #+#    #+#              #
#    Updated: 2023/04/25 18:08:33 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp Zombie.cpp zombieHorde.cpp \

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