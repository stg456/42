while ! mysqladmin ping --user=${MYSQL_USER} --password=${MYSQL_PASSWORD} -h"$MYSQL_HOST" --silent; do
    sleep 1
done

if [ ! -e /var/www/wordpress/wp-config.php ]; then
    mkdir -p /var/www/wordpress && chown -R www-data:www-data /var/www/wordpress && chmod -R 755 /var/www/wordpress # dossier wp
    mkdir -p /var/www/.wp-cli && chown -R www-data:www-data /var/www/.wp-cli && chmod -R 755 /var/www/.wp-cli # dossier wp-cli
    sudo -u www-data wp-cli.phar core download --path="/var/www/wordpress/"
    sudo -u www-data wp-cli.phar config create --path="/var/www/wordpress/" --dbname=${MYSQL_DATABASE} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=${MYSQL_HOST}:3306 --skip-check
    sleep 10
    sudo -u www-data wp-cli.phar core install --path="/var/www/wordpress/" --url=${WP_HOSTNAME} --title=${WP_TITLE} --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL}
    sudo -u www-data wp-cli.phar user create --path="/var/www/wordpress/" ${WP_USER} ${WP_EMAIL} --role=author --user_pass=${WP_PASSWORD}
fi

if [ ! -d /run/php ]; then
	mkdir /run/php
fi

php-fpm7.3 -F
