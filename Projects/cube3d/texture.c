/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:57:26 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/15 17:46:38 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_text_data(void)
{
	g_north.ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->map.north,
			&g_north.width, &g_north.height);
	g_west.ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->map.west,
			&g_west.width, &g_west.height);
	g_south.ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->map.south,
			&g_south.width, &g_south.height);
	g_east.ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->map.east,
			&g_east.width, &g_east.height);
	g_sprite.ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->map.sprite,
			&g_sprite.width, &g_sprite.height);
}

void		init_texture(void)
{
	get_text_data();
	if (g_north.ptr && g_west.ptr && g_south.ptr && g_east.ptr && g_sprite.ptr)
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
		g_sprite.data = (int *)mlx_get_data_addr(g_sprite.ptr,
		&g_sprite.bits_per_pixel,
				&g_sprite.size_line, &g_sprite.endian);
	}
	else
		exit_game(cub, 6);
}

void		ft_empty_trash(float rayangle, int col)
{
	float	distanceprojplane;
	float	raydist;
	float	an;
	float	wallstripheight;
	float	offset;

	an = rayangle - cub->rayAngle;
	raydist = cub->distance * cos(an);
	distanceprojplane = (cub->map.height / 2) / tan(FOV_ANGLE / 2);
	wallstripheight = (TILE_SIZE / raydist) * distanceprojplane;
	offset = ((cub->wasHitVertical == 0) ?
	fmod(cub->wallHitX, TILE_SIZE) : fmod(cub->wallHitY, TILE_SIZE));
	if (cub->isRayFacingDown && !cub->wasHitVertical)
		ft_draw_texture(g_west, col, offset, wallstripheight);
	else if (cub->isRayFacingLeft && cub->wasHitVertical)
		ft_draw_texture(g_east, col, offset, wallstripheight);
	else if (cub->isRayFacingRight && cub->wasHitVertical)
		ft_draw_texture(g_south, col, offset, wallstripheight);
	else if (cub->isRayFacingUp && !cub->wasHitVertical)
		ft_draw_texture(g_north, col, offset, wallstripheight);
	//ft_draw_fc_mini(col, wallstripheight);
}

unsigned int		shadow(unsigned int color, int col)
{
	t_colors			shadow;
	float			fact;
	unsigned int	dark;

	fact = 200 / g_ray_distance[col];
	shadow.r = (((color >> 16) & 0xFF)) * fact;
	shadow.g = (((color >> 8) & 0xFF)) * fact;
	shadow.b = ((color) & (0xFF)) * fact;
	dark = rgb_to_int(shadow.r, shadow.g, shadow.b);
	if (dark > color)
		dark = color;
	return (dark);
}

unsigned int	rgb_to_int(unsigned int r, unsigned int g, unsigned int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}