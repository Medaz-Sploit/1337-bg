/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:15:27 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/30 06:52:44 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int update()
{
    if (g_img.img != NULL)
      mlx_destroy_image(g_cub->mlx_ptr, g_img.img);
    g_img.img = mlx_new_image(g_cub->mlx_ptr, g_cub->map.width, g_cub->map.height);
    g_dst = (int *)mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel, &g_img.line_length,
			&g_img.endian);
	player_step();
	cast();
	ft_draw_sprites();
	if (g_cub->save == 1)
	{
		bmp(g_cub);
		exit(0);
	}
	mlx_put_image_to_window(g_cub->mlx_ptr, g_cub->win_ptr, g_img.img, 0, 0);
	return(0);
}
