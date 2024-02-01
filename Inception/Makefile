NAME = Inception

SRCS = ./srcs/docker-compose.yml

all: run

run: 

up: docker-compose up -d 

down: docker-compose -f ./docker-compose.yml down

# restart: docker-compose restart

# stop: docker-compose -f ./docker-compose.yml stop

clean:	down

fclean: clean

# .PHONY: all up down run clean fclean 