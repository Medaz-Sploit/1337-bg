/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:29:59 by mazoukni          #+#    #+#             */
/*   Updated: 2020/12/16 18:51:03 by mazoukni         ###   ########.fr       */
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

// char* read_file()
// {
// 	int i = 0;
	// int line_num = 0;
	// int line_len = 0;
// 	int fd;
// 	char* line;
	
	
// 	fd = open("map.cub", O_RDONLY);
// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		line_num++;
// 		line_len = ft_strlen(line);
// 		printf("[%d]: [%s]\n", line_len, line);
// 	}
// 	printf("[%d]\n", line_num);
// 	close(fd);
// 	return (line);
// }


int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	int i = 1;
	int j = 1;
	int fd;
	int line_num = 0;
	int line_len = 0;
	int tileColor = 0;
	char* line = NULL;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0 && i < MAP_NUM_ROWS)
	{
		line_num++;
		line_len = ft_strlen(line);
		printf("[%d]: [%s] : [%d]\n", line_len, line, line_num);
		while (j < line_len){
			int tileX = j * TILE_SIZE;
			int tileY = i * TILE_SIZE;
			if (*line == '1' || *line == '0'){
				tileColor = *line == '1' ? 0xFCAFFF : 0x000000;
				line++;
			}
			else{
				line++;
				tileColor = 0x000000;
			}
			draw_block(mlx_ptr, win_ptr, tileX, tileY, tileColor);
			j++;
		}
		i++;
		j = 0;
		// }
	}
	// printf("[%d]\n", line_num);
	close(fd);
	// return (line);
	// while (i < MAP_NUM_ROWS && *line != '\0') {
	// 	while (j < MAP_NUM_COLS){
	// 		int tileX = j * TILE_SIZE;
	// 		int tileY = i * TILE_SIZE;
	// 		int tileColor = *line == '1' ? 0xFCAFFF : 0x000000;
	// 		printf("%c\n", *line);
	// 		draw_block(mlx_ptr, win_ptr, tileX, tileY, tileColor);
	// 		j++;
	// 		line++;
	// 	}
	// 	i++;
	// }
	mlx_loop(mlx_ptr);
}
