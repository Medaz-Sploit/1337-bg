/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:29:59 by mazoukni          #+#    #+#             */
/*   Updated: 2020/12/14 09:36:19 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_block(void *mlx_ptr, void *win_ptr, int tileX, int tileY, int tileColor)
{
	int x = tileX - TILE_SIZE;
	int y = tileY - TILE_SIZE;
	while (x < tileX) 
	{
		while(y < tileY)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y++, tileColor);
		x++;
		y = 0;
	}
}

char* read_file()
{
	int i = 0;
	int line_num = 0;
	int line_len = 0;
	int fd;
	char* line;
	
	
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		line_num++;
		line_len = ft_strlen(line);
		printf("[%d]: [%s]\n", line_len, line);
	}
	printf("[%d]\n", line_num);
	close(fd);
	return (line);
}

// double deg2rad(double degree)
// {
// 	return degree * (PI / 180.0);
// }

// double rad2deg(double radian)
// {
// 	return radian * (180.0 / PI);
// }

// int rayAngle =+ FOV_ANGLE / NUM_RAYS;

// need to make a function to calculate the row and colomns of tha map while ignorine space
// after calculating rows and cols compare all cols and choose the max and insert it to MAP_NUM_COLS
// for the ROWS just get the the valuse of ROWS and insert it 

// int ft_cals(char* line)
// {
// 	int cols;
// 	int rows;
// 	cols = 0;
// 	rows = 0;
// 	{
// 		cols += ft_strlen(line);
// 		rows++;
// 	}
// 	return (len);
// }

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	int i = 1;
	int j = 1;
	char* line = NULL;

	line = read_file();
	printf("[%s]\n", line);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	while (i < MAP_NUM_ROWS && *line != '\0') {
		while (j < MAP_NUM_COLS){
			int tileX = j * TILE_SIZE;
			int tileY = i * TILE_SIZE;
			int tileColor = *line == '1' ? 0xFCAFFF : 0x000000;
			printf("%c\n", *line);
			draw_block(mlx_ptr, win_ptr, tileX, tileY, tileColor);
			j++;
			line++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}
