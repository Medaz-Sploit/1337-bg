/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:41:49 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/08 23:59:13 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int            draw_square(int i, int j)
{
    int x;
    int y;

    x = 0;
    while (x < TILE_SIZE)
    {
        y = 0;
        while(y < TILE_SIZE)
        {
            my_mlx_pixel_put(j * TILE_SIZE + y, i * TILE_SIZE +  x, 0xFF00FF);
            y++;
        } 
        x++;
    }
    return(0);
}

int            draw_2d()
{
    int i; 
    int j;

    i = 0;
    while (cub->map.map[i] != NULL)
    {
        j = 0;
        while (cub->map.map[i][j] != '\0')
        {
            if (cub->map.map[i][j] == '1')
                draw_square(i, j);
            j += 1;
        }
        i++;
    }
    return(0);
}

// function renderCeiling() {
//     noStroke();
//     fill('#414141');
//     rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT/2);
// }

// function renderFloor() {
//     noStroke();
//     fill('#818181');
//     rect(0, WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT)
// }

// function render3DProjectedWalls() {
//     renderCeiling();
//     renderFloor();
    
//     // loop every ray in the array of rays
//     for (var i = 0; i < NUM_RAYS; i++) {
//         var ray = rays[i];

//         // get the perpendicular distance to the wall to fix fishbowl distortion
//         var correctWallDistance = ray.distance * Math.cos(ray.rayAngle - player.rotationAngle);

//         // calculate the distance to the projection plane
//         var distanceProjectionPlane = (WINDOW_WIDTH / 2) / Math.tan(FOV_ANGLE / 2);

//         // projected wall height
//         var wallStripHeight = (TILE_SIZE / correctWallDistance) * distanceProjectionPlane;

//         // set a darker color if the wall is facing north-south
//         var colorBrightness = ray.wasHitVertical ? 255 : 200;

//         // set the correct color based on the wall hit grid content (1=Red, 2=Green, 3=Blue)
//         var colorR = ray.hitWallColor == 1 ? colorBrightness : 0;
//         var colorG = ray.hitWallColor == 2 ? colorBrightness : 0;
//         var colorB = ray.hitWallColor == 3 ? colorBrightness : 0;
//         var alpha = 1.0;

//         fill("rgba(" + colorR + ", " + colorG + ", " + colorB + ", " + alpha + ")");
//         noStroke();

//         // render a rectangle with the calculated projected wall height
//         rect(
//            i * WALL_STRIP_WIDTH,
//            (WINDOW_HEIGHT / 2) - (wallStripHeight / 2),
//            WALL_STRIP_WIDTH,
//            wallStripHeight
//         );
//     }
// }


// void   circle(float x, float y, int radius){
//     float	phi;
// 	float	val;
// 	val = cub->rayAngle;
// 	while (radius >= 0)
// 	{
// 		phi = 0;
// 		while (phi <= 360)
// 		{
// 			y = (cub->rc.pos_y) + (radius * sin(phi * val));
// 			x = (cub->rc.pos_x) + (radius * cos(phi * val));
// 			if (x >= 0 && x < cub->map.width &&
// 			y >= 0 && y < cub->map.height)
// 				my_mlx_pixel_put(x, y, 0xff0000);
// 			phi += 0.1;
// 		}
// 		radius--;
// 	}
// }