/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:11:25 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/28 18:16:50 by mazoukni         ###   ########.fr       */
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
                    cub->rc.camera_x = -(M_PI / 2);
                else if (cub->map.map[i][j] == 'S')
                   cub->rc.camera_x  = M_PI / 2;
                else if (cub->map.map[i][j] == 'W')
                    cub->rc.camera_x = M_PI;
                else if (cub->map.map[i][j] == 'E')
                    cub->rc.camera_x  = 0;
            }
            j += 1;
        }
        i++;
    }
    cub->rc.camera_x = normalizeAngle(cub->rc.camera_x);
}

int     hasWallAtSprite(float x, float y)
{
    int x0 = floor(x / TILE_SIZE);
    int y0 = floor(y / TILE_SIZE);
    if (x0 < 0 || x0 >= cub->map.rows  || y0 < 0 || y0 >= cub->map.columns) 
        return (0);
    else if (cub->map.map[x0][y0] == '2')
		return(1);
	return(0);
}

int     hasWallAt(float x, float y)
{

    int x0 = floor(x / TILE_SIZE);
    int y0 = floor(y / TILE_SIZE);
    if (x0 < 0 || x0 >= cub->map.rows  || y0 < 0 || y0 >= cub->map.columns) 
        return (0);
    return (cub->map.map[x0][y0] == '1');
}

void player_step()
{
    float player_x;
    float player_y;
    cub->rc.camera_x += cub->turndirection * cub->rotationspeed;
    cub->movestep = cub->walkdirection * cub->movespeed;
    player_x = cub->rc.pos_x + cos(cub->rc.camera_x) * cub->movestep * 8;
    player_y = cub->rc.pos_y + sin(cub->rc.camera_x) * cub->movestep * 8;
    float newplayerx = cub->rc.pos_x + cos(cub->rc.camera_x) * cub->movestep;
    float newplayery = cub->rc.pos_y + sin(cub->rc.camera_x) * cub->movestep;
    if (!hasWallAt(player_x, player_y) && !hasWallAtSprite(player_x, player_y))
    {
        cub->rc.pos_x = newplayerx;
        cub->rc.pos_y = newplayery;
    }
}

void rayDir(float angle)
{
    cub->rayAngle = normalizeAngle(angle);
    cub->wallHitX = 0;
    cub->wallHitY = 0;
    cub->distance = 0;
    cub->wasHitVertical = false;
    cub->isRayFacingDown = cub->rayAngle > 0 && cub->rayAngle < M_PI;
    cub->isRayFacingUp = !cub->isRayFacingDown;
    cub->isRayFacingRight = cub->rayAngle < 0.5 * M_PI || cub->rayAngle > 1.5 * M_PI;
    cub->isRayFacingLeft = !cub->isRayFacingRight;
}