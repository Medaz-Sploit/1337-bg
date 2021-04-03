/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:30 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/30 06:49:30 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(int col, float rayAngle)
{
	rayDir(rayAngle);
	float xintercept;
	float yintercept;
	float xstep, ystep;
	bool foundHorzWallHit = false;
	float horzWallHitX = 0;
	float horzWallHitY = 0;
	yintercept = floor(g_cub->rc.pos_y / TILE_SIZE) * TILE_SIZE;
	yintercept += g_cub->isRayFacingDown ? TILE_SIZE : 0;
	xintercept = g_cub->rc.pos_x + (+yintercept - g_cub->rc.pos_y) / tan(rayAngle);
	ystep = TILE_SIZE;
	ystep *= g_cub->isRayFacingUp ? -1 : 1;
	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (g_cub->isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (g_cub->isRayFacingRight && xstep < 0) ? -1 : 1;
	float nextHorzTouchX = xintercept;
	float nextHorzTouchY = yintercept;
	while (nextHorzTouchX >= 0 && nextHorzTouchX < g_cub->map.width * TILE_SIZE && nextHorzTouchY >= 0 && nextHorzTouchY < g_cub->map.height * TILE_SIZE)
	{
		if (hasWallAt(nextHorzTouchX, nextHorzTouchY - (g_cub->isRayFacingUp ? 1 : 0)))
		{
			foundHorzWallHit = true;
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			break;
		} else {
			nextHorzTouchX += xstep;
			nextHorzTouchY += ystep;
		}
	}
	rayDir(rayAngle);
	bool foundVertWallHit = false;
	float vertWallHitX = 0;
	float vertWallHitY = 0;
	xintercept = floor(g_cub->rc.pos_x / TILE_SIZE) * TILE_SIZE;
	xintercept += g_cub->isRayFacingRight ? TILE_SIZE : 0;
	yintercept = g_cub->rc.pos_y + (xintercept - g_cub->rc.pos_x) * tan(rayAngle);
	xstep = TILE_SIZE;
	xstep *= g_cub->isRayFacingLeft ? -1 : 1;
	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (g_cub->isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (g_cub->isRayFacingDown && ystep < 0) ? -1 : 1;
	float nextVertTouchX = xintercept;
	float nextVertTouchY = yintercept;
	while (nextVertTouchX >= 0 && nextVertTouchX < g_cub->map.width * TILE_SIZE && nextVertTouchY >= 0 && nextVertTouchY < g_cub->map.height * TILE_SIZE)
	{
		if (hasWallAt(nextVertTouchX - (g_cub->isRayFacingLeft ? 1 : 0), nextVertTouchY)) {
			foundVertWallHit = true;
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
			break;
		} else {
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}
	}
	float horzHitDistance = (foundHorzWallHit)
		? distanceBetweenPoints(g_cub->rc.pos_x, g_cub->rc.pos_y, horzWallHitX, horzWallHitY)
		: __INT_MAX__;
	float vertHitDistance = (foundVertWallHit)
		? distanceBetweenPoints(g_cub->rc.pos_x, g_cub->rc.pos_y, vertWallHitX, vertWallHitY)
		: __INT_MAX__;
 	g_cub->wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
    g_cub->wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
    g_cub->distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
    g_cub->wasHitVertical = (vertHitDistance < horzHitDistance);
    g_cub->distance *= cos(g_cub->rc.camera_x - rayAngle);
	g_ray_distance[col] = g_cub->distance;
    float perpDistance = g_cub->distance;
    float distanceProjPlane = (g_cub->map.height / 2) / tan(FOV_ANGLE / 2);
    float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;
    int wallStripHeight = projectedWallHeight;
    int wallTopPixel = (g_cub->map.height / 2) - (wallStripHeight / 2);
    wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
    int wallBottomPixel = (g_cub->map.height / 2) + (wallStripHeight / 2);
    wallBottomPixel = wallBottomPixel > g_cub->map.height ? g_cub->map.height : wallBottomPixel;
	g_cub->colo = g_cub->map.floor;
	 dda(g_cub->map.height/2 + wallStripHeight/2, col, g_cub->map.height, col);
	g_cub->colo = g_cub->map.ceiling;
	dda(0, col, g_cub->map.height/2 - wallStripHeight/2, col);
	ft_empty_trash(rayAngle, col);
}

float normalizeAngle(float angle)
{
	float angler = fmod(angle ,(2 * M_PI));
	if (angle < 0)
		angler = (2 * M_PI) + angle;
	return angler;
}

float distanceBetweenPoints(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void dda(float x0, float y0, float x1, float y1)
{
	float dx = x1 - x0;
	float dy = y1 - y0;
	float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	float Xinc = dx / (float) steps;
	float Yinc = dy / (float) steps;
	float X = x0;
	float Y = y0;
	for (int i = 0; i <  steps; i++)
	{
		my_mlx_pixel_put(Y, X, g_cub->colo);
		X += Xinc;
		Y += Yinc;

	}
}

void cast(void)
{
	int i;
	float   rayangle;
	float   angle;

	i = 0;
	rayangle = (FOV_ANGLE / g_cub->map.width);
	angle = (g_cub->rc.camera_x) - (FOV_ANGLE / 2);
	while (i < g_cub->map.width)
	{
		angle = normalizeAngle(angle);
		raycast(i, angle);
		angle += rayangle;
		i++;
	}
}
