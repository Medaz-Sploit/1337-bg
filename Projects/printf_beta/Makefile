# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2020/02/25 21:36:39 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC =	choose_flag.c ft_atoi.c ft_is_negative.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_putnbr.c ft_strlen.c \
		print_decint.c print_pointer.c print_string.c cc.c fetch.c ft_hexatoi.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_printf.c ft_putchar.c ft_putstr.c ft_tolower.c print_hex.c print_prec.c print_zeros.c

OBJ = $(SRC:.c=.o)

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
