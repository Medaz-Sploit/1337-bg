/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:23:02 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/19 16:47:01 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	distance(float x1, float y1, float x2, float y2)
{
	return (hypotf((x2 - x1), (y2 - y1)));
}

void			ft_draw_sprites(void)
{
	int			i;

	i = 0;
	while (i < cub->rc.nbr_sprites) // spirte f map
	{
        // distance mabin player o sprite
		g_s_data[i].distance = distance(cub->rc.pos_x, cub->rc.pos_y,
		g_s_data[i].coord_x, g_s_data[i].coord_y);
		i++;
	}
    // bubble sort 
	ft_sort_sprites();
	i = 0;
    
	while (i < cub->rc.nbr_sprites)
		ft_sprite(i++);
}

void			render_spt(int x, int y, int sp_size, int k)
{
	int			color;
	int			i;
	int			j;

	i = 0;
	color = 0xFF45FF;
	while (i++ < sp_size)
	{
        //window
		if (x + i < 0 || x + i > cub->map.width)
			continue;
        // sprite distance 
		//printf(" g_s_data[k].distance :%f \t || g_ray_distance[x + i] : %f \n ", g_s_data[k].distance, g_ray_distance[x + i]);
		if (g_s_data[k].distance >= g_ray_distance[x + i])
			continue;
		j = 0;
        // sprite size
		while (j++ < sp_size)
		{
			if ((int)(g_sprite.height * (j * g_sprite.width / sp_size) + (i * g_sprite.height / sp_size)) < g_sprite.width * g_sprite.height)
				color = g_sprite.get_data[(int)(g_sprite.height * (j * g_sprite.width / sp_size) + (i * g_sprite.height / sp_size))];
			if (color != 0)
				my_mlx_pixel_put(x + i, y + j, color);
		}
	}
}

void			ft_sprite(int i)
{
	float		sp_size;
	float		x_inter;
	float		y_inter;
	float		sp_angle;

	sp_angle = atan2(g_s_data[i].coord_y - cub->rc.pos_y, g_s_data[i].coord_x - cub->rc.pos_x);
	while (sp_angle - cub->rc.camera_x > M_PI)
		sp_angle -= 2 * M_PI;
	while (sp_angle - cub->rc.camera_x < -M_PI)
		sp_angle += 2 * M_PI;
	if (cub->map.height > cub->map.width)
		sp_size = (cub->map.height / g_s_data[i].distance) * TILE_SIZE;
	else
		sp_size = (cub->map.width / g_s_data[i].distance) * TILE_SIZE;
    
	y_inter = cub->map.height / 2 - sp_size / 2 ;
	x_inter = (sp_angle - cub->rc.camera_x) /
	FOV_ANGLE * cub->map.width + (cub->map.width / 2 - sp_size / 2);
	render_spt(x_inter, y_inter, sp_size, i);
}

void			ft_sort_sprites(void)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < cub->rc.nbr_sprites)
	{
		j = 0;
		while (j < cub->rc.nbr_sprites - 1)
		{
			if (g_s_data[j].distance < g_s_data[j + 1].distance)
			{
				temp = g_s_data[j];
				g_s_data[j] = g_s_data[j + 1];
				g_s_data[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void			init_sprites_pos(void)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (cub->map.map[i] != '\0' && k < cub->rc.nbr_sprites)
	{
		j = 0;
		while (cub->map.map[i][j] != '\0' && k < cub->rc.nbr_sprites)
		{
			if (cub->map.map[i][j] == '2')
			{
				g_s_data[k].coord_x = (i + 0.5) * TILE_SIZE;
				g_s_data[k].coord_y = (j + 0.5) * TILE_SIZE;
				k++;
			}
			j++;
		}
		i++;
	}
}

void			init_sprites(void)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (cub->map.map[i] != '\0')
	{
		j = 0;
		while (cub->map.map[i][j] != '\0')
		{
			if (cub->map.map[i][j] == '2')
				cub->rc.nbr_sprites += 1;
			j++;
		}
		i++;
	}
	init_sprites_pos();
}