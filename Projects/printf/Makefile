# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2020/02/01 19:39:19 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = libftprintf.a
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
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

c: re clean
	gcc tmp/m_pr.c libftprintf.a
