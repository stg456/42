# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 15:24:28 by stgerard          #+#    #+#              #
#    Updated: 2022/05/04 10:53:33 by stgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

SRCS = server.c 
SRCS2 = client.c 
SRCS_ADD = Minitalk_utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = ${SRCS:.c=.o}
OBJS2 = ${SRCS2:.c=.o}
OBJS_ADD = ${SRCS_ADD:.c=.o}

.c.o:
			${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

all: 	${NAME2} ${NAME}

$(NAME):	$(OBJS) ${OBJS_ADD}
			gcc ${CFLAGS} ${SRCS} ${SRCS_ADD}  -o ${NAME}


${NAME2}: 	${OBJS2} ${OBJS_ADD}
			gcc ${CFLAGS} ${SRCS2} ${SRCS_ADD}  -o ${NAME2}

clean:
			${RM} ${OBJS} $(OBJS2) $(OBJS_ADD)

fclean:		clean
			${RM} ${NAME} ${NAME2}

re:			fclean ${NAME2} ${NAME}

.PHONY:		clean fclean re all