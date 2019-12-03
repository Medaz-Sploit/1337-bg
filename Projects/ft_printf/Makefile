# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2019/12/03 19:18:50 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = *.c
OBJ = *.o

all : $(NAME)

$(NAME):	
	$(CC) -g $(FLAGS) -c $(SRC)
	ar -rc  $(NAME) $(OBJ)
	ranlib $(NAME)

fclean:
	rm -f $(NAME)

clean:
	rm -f *.o

re: fclean all
