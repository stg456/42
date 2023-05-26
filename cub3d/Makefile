# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 17:21:41 by stgerard          #+#    #+#              #
#    Updated: 2023/05/26 11:47:05 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f

SRC = ./src/main.c ./src/init.c 

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${MAKE} -sC ./libft
	${MAKE} -sC ./MLX42
	mv ./libft/libft.a ./
	mv ./MLX42/libmlx42.a ./
	#${CC} $(CFLAGS) ${OBJ} libmlx42.a -lglfw -L/Users/${USER}/goinfre/.brew/opt/glfw/lib/ -o ${NAME}
	${CC} $(CFLAGS) ${OBJ} libmlx42.a -lglfw -L/Users/${USER}/42/cub3d/glfw/lib/ -o ${NAME}
	
%.o: %.c
	$(CC) $(CFLAGS)  -I./MLX42/include/MLX42 -I./include -I/Users/${USER}/42/cub3d/glfw/include -c $< -o $@

clean:
	${RM} ${OBJ} libmlx42.a libft.a
	${MAKE} clean -sC ./libft
	

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -sC ./libft

re: fclean all

.PHONY: clean fclean re all
