# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:51:24 by stgerard          #+#    #+#              #
#    Updated: 2023/05/16 16:55:47 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SRC = 

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} $(CFLAGS) ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all