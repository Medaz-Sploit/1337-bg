/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:41:49 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/23 02:31:50 by mazoukni         ###   ########.fr       */
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
            mlx_pixel_put(cub->mlx_ptr, cub->win_ptr, j * TILE_SIZE + y, i * TILE_SIZE +  x, 0xFF5733);
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