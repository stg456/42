# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:51:24 by stgerard          #+#    #+#              #
#    Updated: 2023/05/23 13:26:02 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SRC = main.c check.c init.c load.c \

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${MAKE} -sC ./libft
	${MAKE} -sC ./MLX42
	mv ./libft/libft.a ./
	mv ./MLX42/libmlx42.a ./
	${CC} $(CFLAGS) ${OBJ} libmlx42.a -I include -lglfw -L/Users/${USER}/goinfre/.brew/opt/glfw/lib/ -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS)  -I./MLX42/include/MLX42 -I/Users/${USER}/goinfre/.brew/opt/glfw/include -c $< -o $@

clean:
	${RM} ${OBJ} libmlx42.a libft.a
	${MAKE} clean -sC ./libft
	

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -sC ./libft

re: fclean all

.PHONY: clean fclean re all