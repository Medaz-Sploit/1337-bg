/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:30 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/10 19:02:30 by mazoukni         ###   ########.fr       */
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
	cub->colo = 0xFFFFFF;


	yintercept = floor(cub->rc.pos_y / TILE_SIZE) * TILE_SIZE;
	yintercept += cub->isRayFacingDown ? TILE_SIZE : 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	xintercept = cub->rc.pos_x + (+yintercept - cub->rc.pos_y) / tan(rayAngle);

	// Calculate the increment xstep and ystep
	ystep = TILE_SIZE;
	ystep *= cub->isRayFacingUp ? -1 : 1;

	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (cub->isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (cub->isRayFacingRight && xstep < 0) ? -1 : 1;

	float nextHorzTouchX = xintercept;
	float nextHorzTouchY = yintercept;

	// Increment xstep and ystep until we find a wall
	while (nextHorzTouchX >= 0 && nextHorzTouchX < cub->map.width && nextHorzTouchY >= 0 && nextHorzTouchY < cub->map.height) 
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
	///////////////////////////////////////////
	// VERTICAL RAY-GRID INTERSECTION CODE
	///////////////////////////////////////////
	bool foundVertWallHit = false;
	float vertWallHitX = 0;
	float vertWallHitY = 0;

	// Find the x-coordinate of the closest vertical grid intersenction
	xintercept = floor(cub->rc.pos_x / TILE_SIZE) * TILE_SIZE;
	xintercept += cub->isRayFacingRight ? TILE_SIZE : 0;

	// Find the y-coordinate of the closest vertical grid intersection
	yintercept = cub->rc.pos_y + (xintercept - cub->rc.pos_x) * tan(rayAngle);

	// Calculate the increment xstep and ystep
	xstep = TILE_SIZE;
	xstep *= cub->isRayFacingLeft ? -1 : 1;

	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (cub->isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (cub->isRayFacingDown && ystep < 0) ? -1 : 1;

	float nextVertTouchX = xintercept;
	float nextVertTouchY = yintercept;

	// Increment xstep and ystep until we find a wall
	while (nextVertTouchX >= 0 && nextVertTouchX < cub->map.width && nextVertTouchY >= 0 && nextVertTouchY < cub->map.height) 
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

	// Calculate both horizontal and vertical distances and choose the smallest value
	float horzHitDistance = (foundHorzWallHit)
		? distanceBetweenPoints(cub->rc.pos_x, cub->rc.pos_y, horzWallHitX, horzWallHitY)
		: __INT_MAX__;
	float vertHitDistance = (foundVertWallHit)
		? distanceBetweenPoints(cub->rc.pos_x, cub->rc.pos_y, vertWallHitX, vertWallHitY)
		: __INT_MAX__;

	// only store the smallest distance
 	cub->wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
    cub->wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
    cub->distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
    cub->wasHitVertical = (vertHitDistance < horzHitDistance);

    cub->distance *= cos(cub->rc.camera_x - rayAngle);
    // printf("0%f\n",rayrayAngle);
    // printf("1%f\n",nassim.rotationangle);
    //cub->distance *= cos(rayAngle);
    float perpDistance = cub->distance;
    float distanceProjPlane = (cub->map.height / 2) / tan(FOV_ANGLE / 2);
    float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

    int wallStripHeight = projectedWallHeight;
    int wallTopPixel = (cub->map.width / 2) - (wallStripHeight / 2);
    wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
	
    int wallBottomPixel = (cub->map.width / 2) + (wallStripHeight / 2);
    wallBottomPixel = wallBottomPixel > cub->map.width ? cub->map.width : wallBottomPixel;
    cub->colo = 0xFF0000;
    //dda(0, (cub->map.width / 2) - (wallStripHeight / 2),  col, (cub->map.width / 2) - (wallStripHeight / 2));
	cub->colo = 0xFFFFFF;
	 dda(cub->map.width/2 + wallStripHeight/2, col, cub->map.width, col);
	cub->colo = 0xFF9811;
	dda(cub->map.width/2 - wallStripHeight/2, col,0, col);
   

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

	// calculate steps required for generating pixels 
	float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 

	// calculate increment in x & y for each steps 
	float Xinc = dx / (float) steps; 
	float Yinc = dy / (float) steps; 

	// Put pixel for each step 
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
