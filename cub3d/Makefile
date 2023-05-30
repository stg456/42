# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 17:21:41 by stgerard          #+#    #+#              #
#    Updated: 2023/05/30 11:12:57 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f

SRC = ./src/main.c ./src/init.c ./src/utils.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${MAKE} -sC ./libft/
	${MAKE} -sC ./MLX42
	mv ./libft/libft.a ./
	mv ./MLX42/libmlx42.a ./
	${CC} $(CFLAGS) ${OBJ} libft.a libmlx42.a -lglfw -L./glfw/lib/ -o ${NAME}
	
%.o: %.c
	$(CC) $(CFLAGS)  -I./MLX42/include/MLX42 -I./include -I./glfw/include -c $< -o $@

clean:
	${RM} ${OBJ} libmlx42.a libft.a
	${MAKE} clean -sC ./libft
	

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -sC ./libft

re: fclean all

.PHONY: clean fclean re all
