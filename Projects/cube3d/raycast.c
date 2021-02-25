/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:30 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/25 15:22:45 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(float rayAngle)
{
        float xintercept;
        float yintercept;
        float xstep, ystep;

        
        bool foundHorzWallHit = false;
        float horzWallHitX = 0;
        float horzWallHitY = 0;
        float horzWallColor = 0;

        
        yintercept = floor(cub->rc.pos_y / TILE_SIZE) * TILE_SIZE;
        yintercept += isRayFacingDown ? TILE_SIZE : 0;

        // Find the x-coordinate of the closest horizontal grid intersection
        xintercept = cub->rc.pos_x + (yintercept - cub->rc.pos_y) / tan(rayAngle);

        // Calculate the increment xstep and ystep
        ystep = TILE_SIZE;
        ystep *= isRayFacingUp ? -1 : 1;

        xstep = TILE_SIZE / tan(rayAngle);
        xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
        xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

        float nextHorzTouchX = xintercept;
        float nextHorzTouchY = yintercept;

        // Increment xstep and ystep until we find a wall
        while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT) {
            float wallGridContent = getWallContentAt(
                nextHorzTouchX,
                nextHorzTouchY + (isRayFacingUp ? -1 : 0) // if ray is facing up, force one pixel up so we are inside a grid cell
            );
            if (wallGridContent != 0) {
                foundHorzWallHit = true;
                horzWallHitX = nextHorzTouchX;
                horzWallHitY = nextHorzTouchY;
                horzWallColor = wallGridContent;
                break;
            } else {
                nextHorzTouchX += xstep;
                nextHorzTouchY += ystep;
            }
        }

        ///////////////////////////////////////////
        // VERTICAL RAY-GRID INTERSECTION CODE
        ///////////////////////////////////////////
        bool foundVertWallHit = false;
        float vertWallHitX = 0;
        float vertWallHitY = 0;
        float vertWallColor = 0;

        // Find the x-coordinate of the closest vertical grid intersenction
        xintercept = floor(cub->rc.pos_x / TILE_SIZE) * TILE_SIZE;
        xintercept += isRayFacingRight ? TILE_SIZE : 0;

        // Find the y-coordinate of the closest vertical grid intersection
        yintercept = cub->rc.pos_y + (xintercept - cub->rc.pos_x) * tan(rayAngle);

        // Calculate the increment xstep and ystep
        xstep = TILE_SIZE;
        xstep *= isRayFacingLeft ? -1 : 1;

        ystep = TILE_SIZE * tan(rayAngle);
        ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
        ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

        float nextVertTouchX = xintercept;
        float nextVertTouchY = yintercept;

        // Increment xstep and ystep until we find a wall
        while (nextVertTouchX >= 0 && nextVertTouchX <= WINDOW_WIDTH && nextVertTouchY >= 0 && nextVertTouchY <= WINDOW_HEIGHT) {
            float wallGridContent = getWallContentAt(
                nextVertTouchX + (isRayFacingLeft ? -1 : 0), // if ray is facing left, force one pixel left so we are inside a grid cell
                nextVertTouchY
            );
            if (wallGridContent != 0) {
                foundVertWallHit = true;
                vertWallHitX = nextVertTouchX;
                vertWallHitY = nextVertTouchY;
                vertWallColor = wallGridContent;
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
        if (vertHitDistance < horzHitDistance) {
            wallHitX = vertWallHitX;
            wallHitY = vertWallHitY;
            distance = vertHitDistance;
            hitWallColor = vertWallColor;
            wasHitVertical = true;
        } else {
            wallHitX = horzWallHitX;
            wallHitY = horzWallHitY;
            distance = horzHitDistance;
            hitWallColor = horzWallColor;
            wasHitVertical = false;
        }
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
    int dx = x1 - x0; 
    int dy = y1 - y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = x0; 
    float Y = y0; 
    for (int i = 0; i <= steps; i++) 
    {
        mlx_pixel_put(cub->mlx_ptr, cub->win_ptr, Y, X, 0xFFFFFF);
        X += Xinc;
        Y += Yinc; 

    } 
}

void cast(void)
{
    int i;
    float rayangle;
    
}