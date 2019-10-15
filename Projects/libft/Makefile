# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2019/10/14 21:56:43 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c *.c
	ar -rc $(NAME) *.o
	ranlib	$(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o
	
re: fclean all

