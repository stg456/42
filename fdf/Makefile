# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 16:05:13 by stgerard          #+#    #+#              #
#    Updated: 2022/06/19 12:06:11 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = fdf.c read.c ./libft/get_next_line_utils.c ./libft/get_next_line.c \
./libft/ft_split.c ./libft/ft_atoi.c \
#draw.c
#./libft/ft_bzero.c ./libft/ft_memalloc.c
#./libft/gnlvy.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@



clean:
			${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
