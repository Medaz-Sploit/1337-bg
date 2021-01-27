/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:46:50 by mazoukni          #+#    #+#             */
/*   Updated: 2021/01/27 03:47:34 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_textures(t_cub *cub, char* line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && cub->NO == false)
	{
		cub->NO = true;
		cub->map.NO_Path = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == 'O' && cub->SO == false)
	{
		cub->SO = true;
		cub->map.SO_Path = save_texture(line, i);
	}
	if (line[i] == 'W' && line[i + 1] == 'E' && cub->WE == false)
	{
		cub->WE = true;
		cub->map.WE_Path = save_texture(line, i);
	}
	if (line[i] == 'E' && line[i + 1] == 'A' && cub->EA == false)
	{
		cub->EA = true;
		cub->map.EA_Path = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == ' ' && cub->S == false)
	{
		cub->S = true;
		cub->map.S_Path = save_texture(line, i);
	}
}

void	read_line(t_cub *cub, char* line)
{
	int i;
	
	i = 0;
	if (line[i] == 'R' && line[i + 1] == ' ' && cub->R == false)
		save_r(cub, line, i);
	if (line[i] == 'S' && line[i] == ' ')
	if (line[i] == 'F' && line[i] == ' ')
	if (line[i] == 'C' && line[i] == ' ')
}

char* read_file(char** argv, t_cub *cub)
{
	t_env *env;
	t_map *map;
	int i = 0;
	
	if ((!(fd(argv[1], O_RDONLY)) < 1)
		exit_out(error, 1);
	while (get_next_line(fd, env->line))
	{
		read_line(cub, line);
	}
}