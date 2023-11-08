
NAME = ircserv

#SRC =  main.cpp Server.cpp cmd.cpp Channel.cpp Client.cpp utilsServer.cpp utils2.cpp \
	cmd/invite.cpp cmd/join.cpp cmd/kick.cpp cmd/mode.cpp cmd/nick.cpp \
	cmd/notice.cpp  cmd/password.cpp cmd/privmsg.cpp cmd/quit.cpp \
	cmd/topic.cpp  cmd/cap.cpp utilsChan.cpp
SRC = $(wildcard *.cpp) $(wildcard cmd/*.cpp)

OBJ = $(SRC:.cpp=.o)

CC = c++

#FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
FLAGS = -Wall -Wextra -std=c++98 -g3

all: $(NAME) $(OBJ)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) 

.cpp.o:
	$(CC) $(FLAGS) -o $@ -c $< 
#-fsanitize=address

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
