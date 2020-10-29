# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 05:19:07 by mazoukni          #+#    #+#              #
#    Updated: 2020/10/23 06:12:31 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

# Setup Mysql

wget -qq https://dev.mysql.com/get/mysql-apt-config_0.8.13-1_all.deb
echo "mysql-apt-config mysql-apt-config/select-server select mysql-5.7" | /usr/bin/debconf-set-selections
DEBIAN_FRONTEND=noninteractive dpkg -i mysql-apt-config_0.8.13-1_all.deb
apt-get -qq update
DEBIAN_FRONTEND=noninteractive apt-get -y -qq install mysql-server
service mysql start
echo "CREATE DATABASE wordpress_db;\nGRANT ALL ON wordpress_db.* TO 'wpuser'@'localhost' IDENTIFIED BY 'pass' WITH GRANT OPTION;\nFLUSH PRIVILEGES;\nexit\n" > /db.Mysql
mysql -u root < /db.Mysql

# Setup phpmyadmin

mkdir /var/www/html/phpmyadmin
tar xzf phpMyAdmin-4.9.0.1-english.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
mv /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php
mv /config.inc.php /var/www/html/phpmyadmin/config.inc.php
chmod 660 /var/www/html/phpmyadmin/config.inc.php
chown -R www-data:www-data /var/www/html/phpmyadmin
mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root
echo '\n'

# Setup wordpress
# wp-admin pass : Cec33qiO1VfRNBS3t@

tar xzf latest.tar.gz
mv wordpress/* /var/www/html
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html
rm -rf wordpress
cd /var/www/html
mv wp-config-sample.php wp-config.php
mv /wp-config.php /var/www/html/wp-config.php
mysql -u root wordpress < /wp.sql
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/html
wp core config --dbname=wordpress_db --dbuser=wpuser --dbpass=pass --allow-root --path=/var/www/html/
wp core install --url="127.0.0.1" --title="Medaz-Sploit" --admin_user="medaz" --admin_password="medazpass" --admin_email="medaz@medaz.com" --allow-root --path=/var/www/html

# Setup SSL encryption

echo "ssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;\nssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;" > /etc/nginx/snippets/self-signed.conf
mv /ssl-params.conf /etc/nginx/snippets/ssl-params.conf

# Configure Nginx for wordpress

cd /etc/nginx/sites-enabled
nginx -t
service php7.3-fpm start
service nginx start
bash
