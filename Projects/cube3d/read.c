/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:46:50 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/02 23:27:38 by nabboudi         ###   ########.fr       */
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

static void	buffer_map(t_cub *g_cub, char *line)
{
	char *tmp;

	if (!g_cub->map.tmp)
		g_cub->map.tmp = ft_strdup("");
	else
	{
		tmp = g_cub->map.tmp;
		g_cub->map.tmp = ft_strjoin(g_cub->map.tmp, "\n");
		free(tmp);
	}
	tmp = g_cub->map.tmp;
	g_cub->map.tmp = ft_strjoin(g_cub->map.tmp, line);
	free(tmp);
	g_cub->map.rows++;
}

static void	read_map(t_cub *g_cub, char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1')
	{
		if (g_cub->id.r == 1 && g_cub->id.no == 1 && g_cub->id.so == 1 && \
				g_cub->id.ea == 1 && g_cub->id.we == 1 && g_cub->id.s == 1 && \
				g_cub->id.f == 1 && g_cub->id.c == 1)
		{
			buffer_map(g_cub, line);
			g_cub->id.m++;
			while (i < ft_strlen(line))
			{
				if (line[i] != ' ' && line[i] != '2' && line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != '\0')
					exit_game(g_cub, 11);
				i++;
			}
		}
		else
			exit_game(g_cub, 12);
	}
	else if (g_cub->id.m)
		g_cub->id.m++;
	if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'R' && line[i] != 'N' \
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && \
			line[i] != 'F' && line[i] != 'C' && line[i] != '\0')
		exit_game(g_cub, 10);
}

static void	read_textures(t_cub *g_cub, char *line, int i)
{
	int j;

	j = 0;
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		if (g_cub->id.no >= 1)
			exit_game(g_cub, 14);
		g_cub->id.no++;
		g_cub->map.north = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		if (g_cub->id.so >= 1)
			exit_game(g_cub, 15);
		g_cub->id.so++;
		g_cub->map.south = save_texture(line, i);
	}
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		if (g_cub->id.ea >= 1)
			exit_game(g_cub, 16);
		g_cub->id.ea++;
		g_cub->map.east = save_texture(line, i);
	}
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		if (g_cub->id.we >= 1)
			exit_game(g_cub, 17);
		g_cub->id.we++;
		g_cub->map.west = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == ' ')
	{
		if (g_cub->id.s >= 1)
			exit_game(g_cub, 18);
		g_cub->id.s++;
		g_cub->map.sprite = save_texture(line, i);
	}
}

void	read_lin(t_cub *g_cub, char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'R' && line[i + 1] == ' ' && g_cub->id.r == 0)
		save_res(g_cub, line, i);
	read_textures(g_cub, line, i);
	if (line[i] == 'F' && line[i + 1] == ' ' )
	{
		if (g_cub->id.f >= 1)
			exit_game(g_cub, 19);
		g_cub->id.f++;
		g_cub->map.floor = save_color(g_cub, line, i);
	}
	if (line[i] == 'C' && line[i + 1] == ' ')
	{
		if (g_cub->id.c >= 1)
			exit_game(g_cub, 20);
		g_cub->id.c++;
		g_cub->map.ceiling = save_color(g_cub, line, i);
	}
	read_map(g_cub, line);
}

int			read_fil(char **argv, t_cub *g_cub)
{
	int		fd;
	char	*line;

	if ((fd = open(argv[1], O_RDONLY)) < 1)
		exit_game(g_cub, 7);
	while (get_next_line(fd, &line))
	{
		read_lin(g_cub, line);
		free(line);
		line = NULL;
	}
	read_lin(g_cub, line);
	free(line);
	line = NULL;
	close(fd);
	check_file(g_cub);
	free_tab(g_cub->map.map);
	save_map(g_cub);
	check_map(g_cub);
	return (1);
}

size_t	ft_tablen(char **s)
{
	size_t len;

	len = 0;
	if (s)
	{
		while (s[len] != NULL)
			len++;
	}
	return (len);
}

void		save_res(t_cub *g_cub, char *line, int i)
{
	int tmp;

	g_cub->id.r = 1;
	i++;
	while (ft_isspace(line[i]))
		i++;
	tmp = i;
	while (line[tmp])
	{
		if (ft_isalpha(line[tmp]))
			exit_game(g_cub, 23);
		tmp++;
	}
	if (ft_isdigit(line[i]))
		g_cub->map.width = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		g_cub->map.height = ft_atoi(&line[i]);
}
