#download debian container
FROM debian:stretch-slim

# Expose necessery ports
EXPOSE 80, 443, 3306

# Files to be added 
ADD mysql_setup.sql /tmp/ 
ADD wordpress.conf /etc/httpd/conf.d/

# RUN service mysqld start && \
mysql < /tmp/mysql_setup.sql && \
rm -rf /tmp/mysql_setup.sql*
service mysqld stop

# install necessary tools
RUN apt-get update && apt-get upgrade && \
apt-get install httpd mod_rewrite mod_ssl mod_env php php-common php-cli php-mysql mysql-server unzip && \
rm -rf /var/cache/* &&
wget -P /var/www/html/ https://wordpress.org/latest.zip && \
unzip /var/www/html/latest.zip -d /var/www/html/ && \
rm -rf /var/www/html/latest.zip

# copy wordpress config-sample to config 
RUN cp /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpess/wp-config.php 
