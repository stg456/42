FROM debian:buster

RUN apt-get update -y && apt-get install mariadb-server -y

RUN mkdir -p /etc/mysql/mariadb.conf.d/

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

# RUN mysql -e

