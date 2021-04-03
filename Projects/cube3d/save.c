/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:45:27 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/03 00:59:06 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	alloc_map(t_cub *g_cub)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (g_cub->map.tmp[i])
	{
		if (g_cub->map.tmp[i] == '\n')
		{
			if (g_cub->map.columns < j)
				g_cub->map.columns = j - 1;
			j = 0;
		}
		i++;
		j++;
	}
	if (!(g_cub->map.map = malloc(sizeof(char*) * (g_cub->map.rows + 1))))
		exit_game(g_cub, 6);
	i = 0;
	while (i < g_cub->map.rows)
	{
		if (!(g_cub->map.map[i] = ft_calloc(sizeof(char), \
		(g_cub->map.columns + 1))))
			exit_game(g_cub, 6);
		i++;
	}
}

void		save_map(t_cub *g_cub)
{
	int i;
	int	j;
	int	k;

	i = 0;
	while (g_cub->map.tmp[i])
	{
		if (g_cub->map.tmp[i] == ' ')
			g_cub->map.tmp[i] = '4';
		i++;
	}
	alloc_map(g_cub);
	i = 0;
	j = 0;
	k = 0;
	while (g_cub->map.tmp[k])
	{
		if (g_cub->map.tmp[k] != '\n')
		{
			g_cub->map.map[i][j] = g_cub->map.tmp[k];
			j++;
		}
		else
		{
			g_cub->map.map[i][j] = '\0';
			i++;
			j = 0;
		}
		k++;
	}
	g_cub->map.map[g_cub->map.rows] = NULL;
}

int			save_color(t_cub *g_cub, char *line, int i)
{
	int color;
	int j;

	j = 0;
	i++;
	check_color(g_cub, line, i);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == ',' && ft_isdigit(line[i + 1]))
		exit_game(g_cub, 28);
	check_color(g_cub, line, i);
	color = ft_atoi(&line[i]) * pow(2, 16);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ',' || line[i] == ' ')
	{
		if(line[i] == ',')
			j++;
		i++;
	}
	if (j >= 2)
		exit_game(g_cub, 28);
	check_color(g_cub, line, i);
	color += ft_atoi(&line[i]) * pow(2, 8);
	j = 0;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ',' || line[i] == ' ')
	{
		if(line[i] == ',')
			j++;
		i++;
	}
	if (j >= 2)
		exit_game(g_cub, 28);
	check_color(g_cub, line, i);
	color += ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		exit_game(g_cub, 28);
	return (color);
}

char		*save_texture(char *line, int i)
{
	char	*texture;

	while (ft_isalpha(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	texture = ft_strtrim(&line[i], " ");
	return (texture);
}

void    ressolution(int* x , int* y, char **tab)
{
	if (g_cub->id.r >= 1)
			exit_game(g_cub, 13);
	g_cub->id.r++;
	if (ft_strlen(tab[0]) != 1)
		exit_game(g_cub, 13);
	if (ft_tablen(tab) != 3)
		exit_game(g_cub, 23);
	int i;
	int len = ft_strlen(tab[1]);
	i = -1;
	while (++i < len)
		if (!ft_isdigit(tab[1][i]))
			exit_game(g_cub, 23);
	i = -1;
	len = ft_strlen(tab[2]);
	while (++i < len)
		if (!ft_isdigit(tab[2][i]))
			exit_game(g_cub, 23);
	*x = ft_atoi(tab[1]);
	*y = ft_atoi(tab[2]);
	if (*x > 2561 || *x < 0)
		*x = 2560;
	if (*y > 1440 || *y < 0)
		*y = 1440;
}
