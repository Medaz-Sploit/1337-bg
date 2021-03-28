/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 01:54:01 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/28 18:15:50 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	columns_edges_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->map.rows)
	{
		if (cub->map.map[i][0] != '1' && cub->map.map[i][0] != ' ')
			exit_game(cub, 32);
		i++;
	}
	i = 0;
	j = 0;
	while (i < cub->map.rows)
	{
		while (cub->map.map[i][j])
			j++;
		j--;
		if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != ' ')
			exit_game(cub, 33);
		i++;
		j = 0;
	}
}

static void	rows_edges_map(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->map.map[0][i])
	{
		if (cub->map.map[0][i] != '1' && cub->map.map[0][i] != ' ')
			exit_game(cub, 30);
		i++;
	}
	i = 0;
	while (i < cub->map.columns)
	{
		if (cub->map.map[cub->map.rows - 1][i] != '1' \
				&& cub->map.map[cub->map.rows - 1][i] != ' ' && \
				cub->map.map[cub->map.rows - 1][i] != '\0')
			exit_game(cub, 31);
		i++;
	}
}

static void	edges_map(t_cub *cub)
{
	int i;
	int j;

	i = 1;
	cub->map.map = fill_map();
	while (i < cub->map.rows - 1)
	{
		j = 1;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == ' ' && ((j != 0 && cub->map.map[i]\
					[j - 1] == '0') || (j != cub->map.columns - 1 && \
					cub->map.map[i][j + 1] == '0') || cub->map.map[i - 1][j] \
					== '0' || cub->map.map[i + 1][j] == '0'))
				exit_game(cub, 29);
			j++;
		}
		printf("%s\n", cub->map.map[i]);
		i++;
	}
}

static void	position_map(t_cub *cub, int i, int j)
{
	if (ft_isalpha(cub->map.map[i][j]) && cub->map.map[i][j] != 'N' && \
			cub->map.map[i][j] != 'S' && cub->map.map[i][j] != 'E' && \
			cub->map.map[i][j] != 'W')
		exit_game(cub, 11);
	if ((cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' \
			|| cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W')\
			&& cub->id.player == 0)
	{
		cub->rc.pos_x = (j + 0.5) * TILE_SIZE;
		cub->rc.pos_y = (i + 0.5) * TILE_SIZE;
		cub->map.orientation = cub->map.map[i][j];
		cub->id.player = 1;
	}
	else if ((cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' \
			|| cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W')\
			&& cub->id.player == 1)
		exit_game(cub, 21);
}

void		check_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < cub->map.rows)
	{
		while (cub->map.map[i][j])
		{
			position_map(cub, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	if (cub->id.player == 0)
		exit_game(cub, 22);
	edges_map(cub);
	rows_edges_map(cub);
	columns_edges_map(cub);
}

char **fill_map()
{
    char **tab;
    int i;
    int j;
    tab = malloc(sizeof(char*) * (cub->map.rows + 1));
    i = 0;
    while (i < cub->map.rows)
    {
        tab[i] = malloc(sizeof(char) * cub->map.columns + 1);
        j = 0;
        while (j < cub->map.columns)
        {
            if (j < ft_strlen(cub->map.map[i]))
                tab[i][j] = cub->map.map[i][j];
            else
                tab[i][j] = '1';

            j++;
        }
        tab[i][j] = 0;
        i++;
    }
    tab[i] = NULL;
    free_tab(cub->map.map);
    return tab;
}
