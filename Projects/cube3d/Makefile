# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 21:27:10 by mazoukni          #+#    #+#              #
#    Updated: 2021/03/31 19:29:01 by nabboudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
FLAGS = -g
SRC = 	check.c draw.c key.c map.c bmp.c sprite.c raycast.c render.c \
		cub3d.c ft_issymbol.c exit.c player.c read.c save.c texture.c get_next_line/get_next_line*.c
LIB =	libft.a
FRAMWORK = -lmlx -framework appkit -framework opengl  -D BUFFER_SIZE=1000

all : $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB) $(FRAMWORK)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
