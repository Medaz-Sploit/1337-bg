/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:11:25 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/03 00:56:57 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_pos()
{
    int i;
    int j;

    i = 0;
    while (g_cub->map.map[i] != NULL)
    {
        j = 0;
        while (g_cub->map.map[i][j] != '\0')
        {
            if (g_cub->map.map[i][j] == 'N' || g_cub->map.map[i][j] == 'S' || g_cub->map.map[i][j] == 'W' || g_cub->map.map[i][j] == 'E')
            {
                g_cub->rc.pos_x = (i + 0.5) * TILE_SIZE;
                g_cub->rc.pos_y = (j + 0.5) * TILE_SIZE;
                if (g_cub->map.map[i][j] == 'N')
                    g_cub->rc.camera_x = 3 * M_PI / 2;
                else if (g_cub->map.map[i][j] == 'S')
                   g_cub->rc.camera_x  = 0;
                else if (g_cub->map.map[i][j] == 'W')
                    g_cub->rc.camera_x = M_PI / 2;
                else if (g_cub->map.map[i][j] == 'E')
                    g_cub->rc.camera_x  = M_PI;
            }
            j++;
        }
        i++;
    }
    g_cub->rc.camera_x = normalizeAngle(g_cub->rc.camera_x);
}

int     hasWallAtSprite(float x, float y)
{
    int x0 = floor(x / TILE_SIZE);
    int y0 = floor(y / TILE_SIZE);
    if (x0 < 0 || x0 >= g_cub->map.rows  || y0 < 0 || y0 >= g_cub->map.columns)
        return (0);
    else if (g_cub->map.map[x0][y0] == '2')
		return(1);
	return(0);
}

int     hasWallAt(float x, float y)
{

    int x0 = floor(x / TILE_SIZE);
    int y0 = floor(y / TILE_SIZE);
    if (x0 < 0 || x0 >= g_cub->map.rows  || y0 < 0 || y0 >= g_cub->map.columns)
        return (0);
	else if (g_cub->map.map[x0][y0] == '1')
    	return (1);
	return (0);
}

void player_step()
{
    float player_x;
    float player_y;
    g_cub->rc.camera_x += g_cub->turndirection * g_cub->rotationspeed;
    g_cub->movestep = g_cub->walkdirection * g_cub->movespeed;
    player_x = g_cub->rc.pos_x + cos(g_cub->rc.camera_x) * g_cub->movestep * 14;
    player_y = g_cub->rc.pos_y + sin(g_cub->rc.camera_x) * g_cub->movestep * 14;
    float newplayerx = g_cub->rc.pos_x + cos(g_cub->rc.camera_x) * g_cub->movestep;
    float newplayery = g_cub->rc.pos_y + sin(g_cub->rc.camera_x) * g_cub->movestep;
    if (!hasWallAt(player_x, player_y) && !hasWallAtSprite(player_x, player_y))
    {
        g_cub->rc.pos_x = newplayerx;
        g_cub->rc.pos_y = newplayery;
    }
}

void rayDir(float angle)
{
    g_cub->rayAngle = normalizeAngle(angle);
    g_cub->wallHitX = 0;
    g_cub->wallHitY = 0;
    g_cub->distance = 0;
    g_cub->wasHitVertical = false;
    g_cub->isRayFacingDown = g_cub->rayAngle > 0 && g_cub->rayAngle < M_PI;
    g_cub->isRayFacingUp = !g_cub->isRayFacingDown;
    g_cub->isRayFacingRight = g_cub->rayAngle < 0.5 * M_PI || g_cub->rayAngle > 1.5 * M_PI;
    g_cub->isRayFacingLeft = !g_cub->isRayFacingRight;
}
