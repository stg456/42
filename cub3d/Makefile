# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 17:21:41 by stgerard          #+#    #+#              #
#    Updated: 2023/05/23 11:22:31 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ./src/cub3d.c ./src/init.c \
./src/check_map.c ./src/img.c \
./src/move.c ./src/move2.c ./src/utils_img.c \
./libft/get_next_line.c ./libft/ft_strchr.c ./libft/ft_strjoin.c \
./libft/ft_strnstr.c ./libft/ft_calloc.c ./libft/ft_memcpy.c \
./libft/ft_strlen.c ./libft/ft_split.c ./libft/ft_printf.c \
./libft/ft_printf_utils.c ./libft/ft_printf_utils2.c \
./libft/ft_printf_utils3.c ./libft/ft_printf_utils4.c ./libft/ft_arr_freer.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} $(CFLAGS) ${OBJ} libmlx42.a -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
