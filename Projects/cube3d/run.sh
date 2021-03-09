#!/bin/sh

gcc -g3 main.c save.c map.c draw.c read.c exit.c check.c libft.a get_next_line/get_next_line*.c  -lmlx -framework appkit -framework opengl   -fsanitize=address  -D BUFFER_SIZE=1000
