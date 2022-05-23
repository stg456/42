# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 14:26:33 by stgerard          #+#    #+#              #
#    Updated: 2022/05/05 13:29:33 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c op_swap.c op2_swap.c op3_swap.c \
check_start.c ft_islonglong.c ft_dectobin.c ft_intlen.c \
algo_swap.c getnum.c algo2_swap.c ft_atoi.c ft_bzero.c ft_split.c \
ft_strdup.c ft_strlen.c
#./libft/ft_printf.c ./libft/ft_printf_utils.c ./libft/ft_printf_utils2.c \
#./libft/ft_printf_utils3.c ./libft/ft_printf_utils4.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = ${SRCS:.c=.o}


.c.o:
				${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
				gcc -o ${NAME} ${OBJS} ${CFLAGS}

all: ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			clean fclean re all
