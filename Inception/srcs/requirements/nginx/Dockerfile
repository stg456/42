FROM debian:buster

# docker build -t nginx .    // build en donnant un nom en ETANT DANS LE BON DOSSIER
# docker image ls            // voir l'image lance si le build est reussi
# docker run -it nginx      // run l'image
# docker ps                 // connaitre les docker lance

RUN mkdir -p /etc/nginx/ssl

RUN apt-get update && apt-get -y install nginx openssl 

# RUN     rm -f /etc/nginx/nginx.conf

RUN     openssl req -x509 -nodes -out /etc/nginx/ssl/inception.pem -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=Haut-Rhin/L=Mulhouse/O=42 Network/OU=42/CN=stgerard.42.fr/UID=stgerard"

COPY    ./conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
