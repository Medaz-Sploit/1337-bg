/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:30 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/28 18:01:52 by mazoukni         ###   ########.fr       */
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
	yintercept = floor(cub->rc.pos_y / TILE_SIZE) * TILE_SIZE;
	yintercept += cub->isRayFacingDown ? TILE_SIZE : 0;
	xintercept = cub->rc.pos_x + (+yintercept - cub->rc.pos_y) / tan(rayAngle);
	ystep = TILE_SIZE;
	ystep *= cub->isRayFacingUp ? -1 : 1;
	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (cub->isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (cub->isRayFacingRight && xstep < 0) ? -1 : 1;
	float nextHorzTouchX = xintercept;
	float nextHorzTouchY = yintercept;
	while (nextHorzTouchX >= 0 && nextHorzTouchX < cub->map.width * TILE_SIZE && nextHorzTouchY >= 0 && nextHorzTouchY < cub->map.height * TILE_SIZE) 
	{
		if (hasWallAt(nextHorzTouchX, nextHorzTouchY - (cub->isRayFacingUp ? 1 : 0)))
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
	xintercept = floor(cub->rc.pos_x / TILE_SIZE) * TILE_SIZE;
	xintercept += cub->isRayFacingRight ? TILE_SIZE : 0;
	yintercept = cub->rc.pos_y + (xintercept - cub->rc.pos_x) * tan(rayAngle);
	xstep = TILE_SIZE;
	xstep *= cub->isRayFacingLeft ? -1 : 1;
	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (cub->isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (cub->isRayFacingDown && ystep < 0) ? -1 : 1;
	float nextVertTouchX = xintercept;
	float nextVertTouchY = yintercept;
	while (nextVertTouchX >= 0 && nextVertTouchX < cub->map.width * TILE_SIZE && nextVertTouchY >= 0 && nextVertTouchY < cub->map.height * TILE_SIZE) 
	{
		if (hasWallAt(nextVertTouchX - (cub->isRayFacingLeft ? 1 : 0), nextVertTouchY)) {
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
		? distanceBetweenPoints(cub->rc.pos_x, cub->rc.pos_y, horzWallHitX, horzWallHitY)
		: __INT_MAX__;
	float vertHitDistance = (foundVertWallHit)
		? distanceBetweenPoints(cub->rc.pos_x, cub->rc.pos_y, vertWallHitX, vertWallHitY)
		: __INT_MAX__;
 	cub->wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
    cub->wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
    cub->distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
    cub->wasHitVertical = (vertHitDistance < horzHitDistance);
    cub->distance *= cos(cub->rc.camera_x - rayAngle);
	g_ray_distance[col] = cub->distance;
    float perpDistance = cub->distance;
    float distanceProjPlane = (cub->map.height / 2) / tan(FOV_ANGLE / 2);
    float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;
    int wallStripHeight = projectedWallHeight;
    int wallTopPixel = (cub->map.height / 2) - (wallStripHeight / 2);
    wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
    int wallBottomPixel = (cub->map.height / 2) + (wallStripHeight / 2);
    wallBottomPixel = wallBottomPixel > cub->map.height ? cub->map.height : wallBottomPixel;
	cub->colo = cub->map.floor;
	 dda(cub->map.height/2 + wallStripHeight/2, col, cub->map.height, col);
	cub->colo = cub->map.ceiling;
	dda(0, col, cub->map.height/2 - wallStripHeight/2, col);   
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
		my_mlx_pixel_put(Y, X, cub->colo);
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
	rayangle = (FOV_ANGLE / cub->map.width);
	angle = (cub->rc.camera_x) - (FOV_ANGLE / 2);
	while (i < cub->map.width)
	{
		angle = normalizeAngle(angle);
		raycast(i, angle);
		angle += rayangle;
		i++;
	}
}
