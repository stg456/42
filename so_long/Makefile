# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 17:21:41 by stgerard          #+#    #+#              #
#    Updated: 2022/07/06 16:55:04 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -g3
#DEBUG_FLAG = -g -fsanitize=address -g3
RM = rm -f

SRC = ./srcs/so_long.c ./srcs/init.c ./srcs/check_map.c ./srcs/img.c \
./srcs/move.c ./srcs/move2.c ./srcs/utils_img.c \
./libft/get_next_line.c ./libft/ft_strchr.c ./libft/ft_strjoin.c \
./libft/ft_strnstr.c ./libft/ft_calloc.c ./libft/ft_memcpy.c \
./libft/ft_strlen.c ./libft/ft_split.c ./libft/ft_printf.c \
./libft/ft_printf_utils.c ./libft/ft_printf_utils2.c \
./libft/ft_printf_utils3.c ./libft/ft_printf_utils4.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o: %.c
	$(CC) -g3 -Wall -Wextra -Werror -Imlx -c $< -o $@



clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
