# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:51:24 by stgerard          #+#    #+#              #
#    Updated: 2023/06/07 17:02:29 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SRC = ./src/main.c ./src/check.c ./src/init.c ./src/load.c ./src/utils.c \
		./src/parse.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${MAKE} -sC ./libft
	${MAKE} -sC ./MLX42
	mv ./libft/libft.a ./
	mv ./MLX42/libmlx42.a ./
	${CC} $(CFLAGS) ${OBJ} libft.a libmlx42.a -lglfw -L/Users/${USER}/goinfre/.brew/opt/glfw/lib/ -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS)  -I./MLX42/include/MLX42 -I./include -I/Users/${USER}/goinfre/.brew/opt/glfw/include -c $< -o $@

clean:
	${RM} ${OBJ} libmlx42.a libft.a
	${MAKE} clean -sC ./libft
	

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -sC ./libft

re: fclean all

.PHONY: clean fclean re all