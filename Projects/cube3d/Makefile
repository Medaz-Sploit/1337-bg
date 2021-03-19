# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 21:27:10 by mazoukni          #+#    #+#              #
#    Updated: 2021/03/19 17:00:51 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = cub3D
CC = gcc 
FLAGS = -g3
SRC = 	check.c draw.c key.c map.c sprite.c raycast.c render.c \
		cub3d.c exit.c player.c read.c save.c texture.c
LIB =	get_next_line/get_next_line.h libft/libft.h libft.a get_next_line/get_next_line*.c
FRAMWORK = -lmlx -framework appkit -framework opengl -D BUFFER_SIZE=1000

all : $(NAME)

$(NAME):
	$(CC)  $(FLAGS) $(SRC) $(LIB)  $(FRAMWORK)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	
clean:
	make -C libft/ clean
re: fclean all

libft: 
	make -C libtf/