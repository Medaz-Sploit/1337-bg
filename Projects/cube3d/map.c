/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:54:01 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/03 01:03:11 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	columns_edges_map(t_cub *g_cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_cub->map.rows)
	{
		if (g_cub->map.map[i][0] != '1' && g_cub->map.map[i][0] != '4')
			exit_game(g_cub, 32);
		i++;
	}
	i = 0;
	j = 0;
	while (i < g_cub->map.rows)
	{
		while (g_cub->map.map[i][j])
			j++;
		j--;
		if (g_cub->map.map[i][j] != '1' && g_cub->map.map[i][j] != '4')
			exit_game(g_cub, 33);
		i++;
		j = 0;
	}
}

static void	rows_edges_map(t_cub *g_cub)
{
	int	i;

	i = 0;
	while (g_cub->map.map[0][i])
	{
		if (g_cub->map.map[0][i] != '1' && g_cub->map.map[0][i] != '4')
			exit_game(g_cub, 30);
		i++;
	}
	i = 0;
	while (i < g_cub->map.columns)
	{
		if (g_cub->map.map[g_cub->map.rows - 1][i] != '1' \
				&& g_cub->map.map[g_cub->map.rows - 1][i] != '4' && \
				g_cub->map.map[g_cub->map.rows - 1][i] != '\0')
			exit_game(g_cub, 31);
		i++;
	}
}

static void	edges_map(t_cub *g_cub)
{
	int	i;
	int	j;

	g_cub->map.map = fill_map();
	i = 1;
	while (i < g_cub->map.rows - 1)
	{
		j = 1;
		while (g_cub->map.map[i][j])
		{
			if (condition(g_cub->map.map, i, j))
				exit_game(g_cub, 30);
			j++;
		}
		i++;
	}
}

static void	position_map(t_cub *g_cub, int i, int j)
{
	if (ft_isalpha(g_cub->map.map[i][j]) && g_cub->map.map[i][j] != 'N' && \
			g_cub->map.map[i][j] != 'S' && g_cub->map.map[i][j] != 'E' && \
			g_cub->map.map[i][j] != 'W')
		exit_game(g_cub, 11);
	if ((g_cub->map.map[i][j] == 'N' || g_cub->map.map[i][j] == 'S' \
			|| g_cub->map.map[i][j] == 'E' || g_cub->map.map[i][j] == 'W')\
			&& g_cub->id.player == 0)
	{
		g_cub->rc.pos_x = (j + 0.5) * TILE_SIZE;
		g_cub->rc.pos_y = (i + 0.5) * TILE_SIZE;
		g_cub->map.orientation = g_cub->map.map[i][j];
		g_cub->id.player = 1;
	}
	else if ((g_cub->map.map[i][j] == 'N' || g_cub->map.map[i][j] == 'S' \
			|| g_cub->map.map[i][j] == 'E' || g_cub->map.map[i][j] == 'W')\
			&& g_cub->id.player == 1)
		exit_game(g_cub, 21);
}

void	check_map(t_cub *g_cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g_cub->map.rows)
	{
		while (g_cub->map.map[i][j])
		{
			position_map(g_cub, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	if (g_cub->id.player == 0)
		exit_game(g_cub, 22);
	edges_map(g_cub);
	rows_edges_map(g_cub);
	columns_edges_map(g_cub);
}

int	condition(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || \
map[i][j] == 'E' || map[i][j] == 'W')
		if (map[i - 1][j] == '4' || map[i + 1][j] == '4' || \
map[i][j - 1] == '4' || map[i][j + 1] == '4')
			return (1);
	return (0);
}
