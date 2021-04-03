/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:57:26 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/02 16:47:20 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_text_data(void)
{
	g_north.ptr = mlx_xpm_file_to_image(g_cub->mlx_ptr, g_cub->map.north,
			&g_north.width, &g_north.height);
	g_west.ptr = mlx_xpm_file_to_image(g_cub->mlx_ptr, g_cub->map.west,
			&g_west.width, &g_west.height);
	g_south.ptr = mlx_xpm_file_to_image(g_cub->mlx_ptr, g_cub->map.south,
			&g_south.width, &g_south.height);
	g_east.ptr = mlx_xpm_file_to_image(g_cub->mlx_ptr, g_cub->map.east,
			&g_east.width, &g_east.height);
	g_sprite.img_ptr = mlx_xpm_file_to_image(g_cub->mlx_ptr, g_cub->map.sprite,
			&g_sprite.width, &g_sprite.height);
}

void		init_texture(void)
{
	get_text_data();
	if (g_north.ptr && g_west.ptr && g_south.ptr && g_east.ptr && g_sprite.img_ptr)
	{
		g_north.data = (int *)mlx_get_data_addr(g_north.ptr,
		&g_north.bits_per_pixel,
				&g_north.size_line, &g_north.endian);
		g_west.data = (int *)mlx_get_data_addr(g_west.ptr,
		&g_west.bits_per_pixel,
				&g_west.size_line, &g_west.endian);
		g_south.data = (int *)mlx_get_data_addr(g_south.ptr,
		&g_south.bits_per_pixel,
				&g_south.size_line, &g_south.endian);
		g_east.data = (int *)mlx_get_data_addr(g_east.ptr,
		&g_east.bits_per_pixel,
				&g_east.size_line, &g_east.endian);
		g_sprite.get_data = (int *)mlx_get_data_addr(g_sprite.img_ptr,
		&g_sprite.bits_per_pixel,
				&g_sprite.size_line, &g_sprite.endian);
	}
	else
		exit_game(g_cub, 6);
}

void		ft_empty_trash(float rayangle, int col)
{
	float	distanceprojplane;
	float	raydist;
	float	an;
	float	wallstripheight;
	float	offset;

	an = rayangle - g_cub->rayAngle;
	raydist = g_cub->distance * cos(an);
	distanceprojplane = (g_cub->map.height / 2) / tan(FOV_ANGLE / 2);
	wallstripheight = (TILE_SIZE / raydist) * distanceprojplane;
	offset = ((g_cub->wasHitVertical == 0) ?
	fmod(g_cub->wallHitX, TILE_SIZE) : fmod(g_cub->wallHitY, TILE_SIZE));
	if (g_cub->isRayFacingDown && !g_cub->wasHitVertical)
		ft_draw_texture(g_west, col, offset, wallstripheight);
	else if (g_cub->isRayFacingLeft && g_cub->wasHitVertical)
		ft_draw_texture(g_east, col, offset, wallstripheight);
	else if (g_cub->isRayFacingRight && g_cub->wasHitVertical)
		ft_draw_texture(g_south, col, offset, wallstripheight);
	else if (g_cub->isRayFacingUp && !g_cub->wasHitVertical)
		ft_draw_texture(g_north, col, offset, wallstripheight);
}
