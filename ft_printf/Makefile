# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 16:31:59 by stgerard          #+#    #+#              #
#    Updated: 2022/03/24 17:02:53 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c \
ft_printf_utils3.c ft_printf_utils4.c		

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
				ar rcs $(NAME) $(OBJ)

%.o: %.c
				$(CC) -I. ${INCLUDES} -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
				$(RM) $(OBJ)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
