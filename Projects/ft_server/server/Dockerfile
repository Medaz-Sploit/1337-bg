# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 10:40:31 by mazoukni          #+#    #+#              #
#    Updated: 2020/03/13 12:53:25 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update\
    && apt-get install wget lsb-release gnupg unzip curl nginx vim php7.3 php7.3-fpm php7.3-curl php7.3-gd php7.3-intl php7.3-mbstring php7.3-soap php7.3-xml php7.3-xmlrpc php7.3-zip php7.3-mysql -y \
    && wget http://repo.mysql.com/mysql-apt-config_0.8.13-1_all.deb \
    && wget http://wordpress.org/latest.tar.gz \
    && wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-english.tar.gz
    
COPY $PWD/srcs/run.sh /run.sh
COPY $PWD/srcs/setup.sh /setup.sh

RUN echo "daemon off;" >> /etc/nginx/nginx.conf
# CMD [ "sh", "/run.sh" ]