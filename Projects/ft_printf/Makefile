# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2019/12/12 03:16:21 by mazoukni         ###   ########.fr        #
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
	rm -f *.o

clean:
	rm -f *.o

re: fclean all
