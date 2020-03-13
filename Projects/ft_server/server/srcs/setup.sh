# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 10:40:20 by mazoukni          #+#    #+#              #
#    Updated: 2020/03/13 13:49:55 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh


# Setup mysql

wget -qq https://dev.mysql.com/get/mysql-apt-config_0.8.13-1_all.deb
echo "mysql-apt-config mysql-apt-config/select-server select mysql-5.7" | /usr/bin/debconf-set-selections
DEBIAN_FRONTEND=noninteractive dpkg -i mysql-apt-config_0.8.13-1_all.deb
apt-get -qq update
DEBIAN_FRONTEND=noninteractive apt-get -y -qq install mysql-server
service mysql start                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
echo "CREATE DATABASE wordpress_db;\nGRANT ALL ON wordpress_db.* TO 'wpuser'@'localhost' IDENTIFIED BY 'pass' WITH GRANT OPTION;\nFLUSH PRIVILEGES;\nexit\n" > /db.Mysql
mysql -u root < /db.Mysql

#Setup phpmyadmin

mkdir /var/www/html/phpmyadmin
tar xzf phpMyAdmin-4.9.0.1-english.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
mv /var/www/html/phpmyadmin/config.simple.inc.php /var/www/html/phpmyadmin/config.inc.php
chmod 660 /var/www/html/phpmyadmin/config.inc.php
chown -R www-data:www-data /var/www/html/phpmyadmin

#Setup Wordpess 

tar xzf latest.tar.gz
mv wordpress/* /var/www/html
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html
rm -rf wordpress
cd /var/www/html
mv wp-config-sample.php wp-config.php

# Configure Nginx for wordpress

cd /etc/nginx/sites-enabled
ln -s ../sites-available/default .
nginx -t 
service php7.3-fpm start
service nginx start