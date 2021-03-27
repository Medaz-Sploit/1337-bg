/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:46:50 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/26 17:07:12 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || \
	c == '\f' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

static void	buffer_map(t_cub *cub, char *line)
{
	if (!cub->map.tmp)
		cub->map.tmp = ft_strdup("");
	else
		cub->map.tmp = ft_strjoin(cub->map.tmp, "\n");
	cub->map.tmp = ft_strjoin(cub->map.tmp, line);
	cub->map.rows++;
}

static void	read_map(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
	{
		if (cub->id.r == 1 && cub->id.no == 1 && cub->id.so == 1 && \
				cub->id.ea == 1 && cub->id.we == 1 && cub->id.s == 1 && \
				cub->id.f == 1 && cub->id.c == 1)
		{
			buffer_map(cub, line);
			cub->id.m++;
		}
		else
			exit_game(cub, 12);
	}
	else if (cub->id.m)
		cub->id.m++;
	if (line[i] != '0' && line[i] != '1' && line[i] != 'R' && line[i] != 'N' \
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && \
			line[i] != 'F' && line[i] != 'C' && line[i] != '\0')
		exit_game(cub, 10);
}

static void	read_textures(t_cub *cub, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && cub->id.no == 0)
	{
		cub->id.no = 1;
		cub->map.north = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == 'O' && cub->id.so == 0)
	{
		cub->id.so = 1;
		cub->map.south = save_texture(line, i);
	}
	if (line[i] == 'E' && line[i + 1] == 'A' && cub->id.ea == 0)
	{
		cub->id.ea = 1;
		cub->map.east = save_texture(line, i);
	}
	if (line[i] == 'W' && line[i + 1] == 'E' && cub->id.we == 0)
	{
		cub->id.we = 1;
		cub->map.west = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == ' ' && cub->id.s == 0)
	{
		cub->id.s = 1;
		cub->map.sprite = save_texture(line, i);
	}
}

static void	read_line(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	check_identifier(cub, line);
	if (line[i] == 'R' && line[i + 1] == ' ' && cub->id.r == 0)
		save_res(cub, line, i);
	read_textures(cub, line, i);
	if (line[i] == 'F' && line[i + 1] == ' ' && cub->id.f == 0)
	{
		cub->id.f = 1;
		cub->map.floor = save_color(cub, line, i);
	}
	if (line[i] == 'C' && line[i + 1] == ' ' && cub->id.c == 0)
	{
		cub->id.c = 1;
		cub->map.ceiling = save_color(cub, line, i);
	}
	read_map(cub, line);
}

int			read_fil(char **argv, t_cub *cub)
{
	int		fd;
	char	*line;
	char	*tmp;


	if ((fd = open(argv[1], O_RDONLY)) < 1)
		exit_game(cub, 7);
	while (get_next_line(fd, &line))
	{
		read_line(cub, line);
		free(line);
		line = NULL;
	}
	read_line(cub, line);
	free(line);
	line = NULL;
	close(fd);
	check_file(cub);
	free_tab(cub->map.map);
	save_map(cub);
	check_map(cub);
	return (1);
}
