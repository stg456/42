FROM debian:buster

RUN apt-get -y update && apt-get -y install wget\
											php7.3\
											php-fpm\
											php-mysql\
											mariadb-client\
											sudo

# RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

# de-tar
# RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

# RUN		chown -R root:root /var/www/wordpress  # super dangereux

COPY ./www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./install_wordpress.sh /install_wordpress.sh

RUN chmod 700 /install_wordpress.sh

RUN mkdir -p /run/php && touch /run/php/php7.3-fpm.pid
RUN chown www-data:www-data /run/php/php7.3-fpm.pid
RUN chmod 755 /run/php/php7.3-fpm.pid 

RUN wget -O /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x /usr/local/bin/wp

COPY ./wp-config.php /wp-config.php

ENTRYPOINT ["/bin/sh", "/install_wordpress.sh"]
EXPOSE 9000