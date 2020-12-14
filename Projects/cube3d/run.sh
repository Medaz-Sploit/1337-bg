#!/bin/sh

gcc -g3 cub3d.c -lmlx -framework appkit -framework opengl   -fsanitize=address  -D BUFFER_SIZE=1000 libft.a get_next_line/get_next_line.c get_next_line/get_next_line.h get_next_line/get_next_line_utils.c && ./a.out
