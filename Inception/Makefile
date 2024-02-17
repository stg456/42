NAME = Inception

SRCS = ./srcs/docker-compose.yml

all: refresh

refresh:
		@docker-compose -f srcs/docker-compose.yml up -d --build

stop:
		@docker-compose -f srcs/docker-compose.yml stop

restart:
		@docker-compose -f srcs/docker-compose.yml restart

clean:	stop
		docker system prune -af

fclean: clean
		sudo rm -rf /home/stgerard/data/mariadb/*
		sudo rm -rf /home/stgerard/data/wordpress/*

re: fclean refresh

.PHONY: all stop refresh restart clean fclean re
