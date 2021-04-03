/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:01:38 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/03 01:00:01 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_identifier(t_cub *g_cub, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'R' && g_cub->id.r == 1)
		exit_game(g_cub, 13);
	if (line[i] == 'N' && line[i + 1] == 'O' && g_cub->id.no == 1)
		exit_game(g_cub, 14);
	if (line[i] == 'S' && line[i + 1] == 'O' && g_cub->id.so == 1)
		exit_game(g_cub, 15);
	if (line[i] == 'E' && line[i + 1] == 'A' && g_cub->id.ea == 1)
		exit_game(g_cub, 16);
	if (line[i] == 'W' && line[i + 1] == 'E' && g_cub->id.we == 1)
		exit_game(g_cub, 17);
	if (line[i] == 'S' && line[i + 1] == ' ' && g_cub->id.s == 1)
		exit_game(g_cub, 18);
	if (line[i] == 'F' && line[i + 1] == ' ' && g_cub->id.f == 1)
		exit_game(g_cub, 19);
	if (line[i] == 'C' && line[i + 1] == ' ' && g_cub->id.c == 1)
		exit_game(g_cub, 20);
}

void	check_file(t_cub *g_cub)
{
	if (g_cub->id.r == 0 && g_cub->id.no == 0 && g_cub->id.so == 0 && \
			g_cub->id.ea == 0 && g_cub->id.we == 0 && g_cub->id.s == 0 && \
			g_cub->id.f == 0 && g_cub->id.c == 0 && g_cub->id.m == 0)
		exit_game(g_cub, 8);
	if (g_cub->id.m == 0)
		exit_game(g_cub, 9);
}

void	check_color(t_cub *g_cub, char *line, int i)
{
	int	tmp;

	if (i == 1)
	{
		while (line[i])
		{
			if (ft_issymbol(line[i]) || ft_isalpha(line[i]))
				exit_game(g_cub, 26);
			i++;
		}
	}
	else
	{
		tmp = ft_atoi(&line[i]);
		if (tmp < 0 || tmp > 255)
			exit_game(g_cub, 27);
	}
}

char	**fill_map(void)
{
	int		i;

	i = -1;
	g_tab = malloc(sizeof(char *) * (g_cub->map.rows + 1));
	i = iterate_map(i);
	g_tab[i] = NULL;
	free(g_cub->map.map);
	return (g_tab);
}

int	iterate_map(int i)
{
	int	j;

	if (!g_tab)
		exit_game(g_cub, 6);
	while (++i < g_cub->map.rows)
	{
		g_tab[i] = malloc(sizeof(char) * g_cub->map.columns + 1);
		if (!(g_tab[i]))
			exit_game(g_cub, 6);
		j = -1;
		while (++j < g_cub->map.columns)
		{
			if (j < ft_strlen(g_cub->map.map[i]))
				g_tab[i][j] = g_cub->map.map[i][j];
			else
				g_tab[i][j] = '4';
		}
		g_tab[i][j] = '\0';
		free(g_cub->map.map[i]);
	}
	return (i);
}
