/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:41:49 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/31 21:27:45 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_texture(t_image ptr, int col, float offset, \
		float wallstripheight)
{
	g_draw.start = (g_cub->map.height / 2) - (wallstripheight / 2);
	g_draw.end = (g_cub->map.height / 2) + (wallstripheight / 2);
	g_draw.texture_y = 0;
	g_draw.offset_x = ternary((g_cub->wasHitVertical), (int)g_cub->wallHitY % TILE_SIZE, \
						(int)g_cub->wallHitX % TILE_SIZE);
	while (g_draw.start < g_draw.end)
	{
		g_draw.dist_from_top = g_draw.start + (wallstripheight \
								/ 2) - (g_cub->map.height / 2);
		g_draw.offset_y = (int)(g_draw.dist_from_top * \
							(float)TILE_SIZE / wallstripheight);
		g_draw.color = ptr.data[g_draw.offset_y * TILE_SIZE + g_draw.offset_x];
		my_mlx_pixel_put(col, g_draw.start, g_draw.color);
		g_draw.start++;
	}
}

int	ternary(int condition, int ret1, int ret2)
{
	if (condition)
		return (ret1);
	else
		return (ret2);
}
