/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:11:25 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/11 15:11:25 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void			ft_draw_sprites(void)
{
	int			i;

	i = 0;
	while (i < g_data.nb_of_sprites) // spirte f map
	{
        // distance mabin player o sprite
		g_s_data[i].distance = ft_distancebetweenpoints(cub->rc.pos_x, cub->rc.pos_y,
		g_s_data[i].x, g_s_data[i].y);
		i++;
	}
    // bubble sort 
	ft_sort_sprites();
	i = 0;
    
	while (i < g_data.nb_of_sprites)
		ft_sprite(i++);
}

void			render_spt(int x, int y, int sp_size, int k)
{
	int			color;
	int			i;
	int			j;

	i = 0;
	color = 0;
	while (i++ < sp_size)
	{
        //window
		if (x + i < 0 || x + i > cub->map.width)
			continue;
        // sprite distance 
		if (g_s_data[k].distance >= g_ray_distance[x + i])
			continue;
		j = 0;
        // sprite size
		while (j++ < sp_size)
		{
			if ((int)(g_sprite.height * (j * g_sprite.width / sp_size) +
			(i * g_sprite.height / sp_size)) < g_sprite.width * g_sprite.height)
				color = g_sprite.data[(int)(g_sprite.height *
				(j * g_sprite.width / sp_size) +
				(i * g_sprite.height / sp_size))];
			if (color != 0)
				ft_pixel_put(x + i, y + j, color);
		}
	}
}

void			ft_sprite(int i)
{
	float		sp_size;
	float		x_inter;
	float		y_inter;
	float		sp_angle;

	sp_angle = atan2(g_s_data[i].y - cub->rc.pos_y, g_s_data[i].x - cub->rc.pos_x);
	while (sp_angle - cub->rc.camera_x > M_PI)
		sp_angle -= 2 * M_PI;
	while (sp_angle - cub->rc.camera_x < -M_PI)
		sp_angle += 2 * M_PI;
        // window
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
	t_sprites	temp;

	i = 0;
	while (i < g_data.nb_of_sprites)
	{
		j = 0;
		while (j < g_data.nb_of_sprites - 1)
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
	while (cub->map.map[i] != '\0' && k < g_data.nb_of_sprites)
	{
		j = 0;
		while (cub->map.map[i][j] != '\0' && k < g_data.nb_of_sprites)
		{
			if (cub->map.map[i][j] == '2')
			{
				g_s_data[k].x = (j + 0.5) * TILE_SIZE;
				g_s_data[k].y = (i + 0.5) * TILE_SIZE;
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
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (cub->map.map[i] != '\0')
	{
		j = 0;
		while (cub->map.map[i][j] != '\0')
		{
			if (cub->map.map[i][j] == '2')
				g_data.nb_of_sprites += 1;
			j++;
		}
		i++;
	}
	init_sprites_pos();
}



void player_pos()
{
    int i; 
    int j;

    i = 0;
    while (cub->map.map[i] != NULL)
    {
        j = 0;
        while (cub->map.map[i][j] != '\0')
        {
            if (cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' || cub->map.map[i][j] == 'W' || cub->map.map[i][j] == 'E')
            {
                cub->rc.pos_x = (i + 0.5) * TILE_SIZE;
                cub->rc.pos_y = (j + 0.5) * TILE_SIZE;
                if (cub->map.map[i][j] == 'N')
                    cub->rc.camera_x = -(M_PI / 2);
                else if (cub->map.map[i][j] == 'S')
                   cub->rc.camera_x  = M_PI / 2;
                else if (cub->map.map[i][j] == 'W')
                    cub->rc.camera_x = M_PI;
                else if (cub->map.map[i][j] == 'E')
                    cub->rc.camera_x  = 0;
            }
            j += 1;
        }
        i++;
    }
    cub->rc.camera_x = normalizeAngle(cub->rc.camera_x);
}

int     hasWallAt(float x, float y)
{

    int x0 = floor(x / TILE_SIZE);
    int y0 = floor(y / TILE_SIZE);
    if (x0 < 0 || x0 >= 12  || y0 < 0 || y0 >= 34) 
        return (0);
    return (cub->map.map[x0][y0] == '1');
}

void player_step()
{
    float player_x;
    float player_y;
    cub->rc.camera_x += cub->turndirection * cub->rotationspeed;
    
    cub->movestep = cub->walkdirection * cub->movespeed;
    player_x = cub->rc.pos_x + cos(cub->rc.camera_x) * cub->movestep * 8;
    player_y = cub->rc.pos_y + sin(cub->rc.camera_x) * cub->movestep * 8;
    float newplayerx = cub->rc.pos_x + cos(cub->rc.camera_x) * cub->movestep;
    float newplayery = cub->rc.pos_y + sin(cub->rc.camera_x) * cub->movestep;

    if (!hasWallAt(player_x, player_y))
    {
        cub->rc.pos_x = newplayerx;
        cub->rc.pos_y = newplayery;
    }
}

void rayDir(float angle)
{
    cub->rayAngle = normalizeAngle(angle);
    cub->wallHitX = 0;
    cub->wallHitY = 0;
    cub->distance = 0;
    cub->wasHitVertical = false;

    cub->isRayFacingDown = cub->rayAngle > 0 && cub->rayAngle < M_PI;
    cub->isRayFacingUp = !cub->isRayFacingDown;

    cub->isRayFacingRight = cub->rayAngle < 0.5 * M_PI || cub->rayAngle > 1.5 * M_PI;
    cub->isRayFacingLeft = !cub->isRayFacingRight;
}