NAME = Inception

SRCS = ./srcs/docker-compose.yml

all: refresh

refresh:
		@docker-compose -f srcs/docker-compose.yml up -d --build

stop:
		@docker-compose -f srcs/docker-compose.yml stop

# restart: docker-compose restart

clean:	stop
		rm -rf /home/stgerard/data/mariadb/*
		rm -rf /home/stgerard/data/wordpress/*

fclean: clean
		docker system prune -af

.PHONY: all down refresh clean fclean