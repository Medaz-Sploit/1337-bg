# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2020/01/27 16:53:35 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = libftprintf.a
CC = gcc
FLAGS = -g 
SRC = *.c
OBJ = *.o

all : $(NAME)

$(NAME):	
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc  $(NAME) $(OBJ)
	ranlib $(NAME)

fclean:
	rm -f $(NAME)
	rm -f *.o

clean:
	rm -f *.o

re: fclean all
