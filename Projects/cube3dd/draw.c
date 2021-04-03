/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:41:49 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/28 18:13:14 by mazoukni         ###   ########.fr       */
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
            my_mlx_pixel_put(j * TILE_SIZE + y , i * TILE_SIZE +  x , 0x65FF12);
            y++;
        } 
        x++;
    }
    return(0);
}

int            draw_2d(void)
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

void		ft_draw_texture(t_image ptr, int col, float offset, float wallstripheight)
{
	int	start;
	int	end;
	float	texture_y;
    int     color;
    int offset_x;
    int offset_y;
    int dist_from_top;

	start = (cub->map.height / 2) - (wallstripheight / 2);
	end = (cub->map.height / 2) + (wallstripheight / 2) ;
	texture_y = 0;
	offset_x =  (cub->wasHitVertical) ? (int)cub->wallHitY % TILE_SIZE : (int)cub->wallHitX % TILE_SIZE;
    while (start < end)
	{
        dist_from_top = start + (wallstripheight/ 2) - (cub->map.height / 2);
        offset_y = (int)(dist_from_top * (float)TILE_SIZE / wallstripheight);
        color = ptr.data[offset_y * TILE_SIZE + offset_x];
		my_mlx_pixel_put(col, start, color);
		start++;
	}
}