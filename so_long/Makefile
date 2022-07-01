# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 17:21:41 by stgerard          #+#    #+#              #
#    Updated: 2022/07/01 17:04:27 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -g3
#DEBUG_FLAG = -g -fsanitize=address -g3
RM = rm -f

SRC = so_long.c init.c check_map.c img.c \
./libft/get_next_line.c ./libft/ft_strchr.c ./libft/ft_strjoin.c \
./libft/ft_strnstr.c ./libft/ft_calloc.c ./libft/ft_memcpy.c ./libft/ft_split.c \
./libft/ft_strlen.c
#./libft/ft_line_length.c ./libft/ft_count_lines.c \
#./libft/ft_split.c ./libft/ft_atoi.c
#./libft/ft_bzero.c ./libft/ft_memalloc.c \
#./libft/ft_calloc.c

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
