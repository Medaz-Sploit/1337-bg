/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:11:25 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/25 15:20:38 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_pos()
{
    int i; 
    int j;

    i = 0;
    while (cub->map.map[i] != NULL)
    {
        j = 0;
        while (cub->map.map[i][j] != '\0')
        {
            if (cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' || cub->map.map[i][j] == 'W' || cub->map.map[i][j] == 'E')
            {
                cub->rc.pos_x = (i + 0.5) * TILE_SIZE;
                cub->rc.pos_y = (j + 0.5) * TILE_SIZE;
                if (cub->map.map[i][j] == 'N')
                    dirangle = -(M_PI / 2);
                else if (cub->map.map[i][j] == 'S')
                    dirangle  = M_PI / 2;
                else if (cub->map.map[i][j] == 'W')
                    dirangle = M_PI;
                else if (cub->map.map[i][j] == 'E')
                    dirangle  = 0;
            }
            j += 1;
        }
        i++;
    }
    dirangle = normalizeAngle(dirangle);
}

int hasWallAt(float x, float y)
{
    
}

void player_step()
{
    
}