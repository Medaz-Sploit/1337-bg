/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:15:27 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/28 18:05:43 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int update()
{
    if (img.img != NULL)
      mlx_destroy_image(cub->mlx_ptr, img.img);
    img.img = mlx_new_image(cub->mlx_ptr, cub->map.width, cub->map.height);
    dst = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
    draw_2d();
    player_step();
    cast();
    ft_draw_sprites();
    if (cub->save == 1)
    {
		  bmp(cub);
      exit(0);
    }
    mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, img.img, 0, 0);
    return(0);
}