FROM debian:buster

# docker build -t nginx .    // builr en donnant un nom en ETANT DANS LE BON DOSSIER
# docker image ls            // voir l'image lance si le build est reussi
# docker run -it nginx      // run l'image
# docker ps                 // connaitre les docker lance

RUN     apk update && apk upgrade && apk add \
            openssl \
            nginx   \
            curl    \
            vim     \
            sudo    \

RUN     rm -f /etc/nginx/nginx.conf

COPY    ./config/nginx.conf /etc/nginx/nginx.conf
COPY    scripts/setup_nginx.sh /setup_nginx.sh

RUN     chmod -R +x /setup_nginx.sh

EXPOSE 443

ENTRYPOINT  ["sh", "setup_nginx.sh"]
