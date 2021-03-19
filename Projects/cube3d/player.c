/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:11:25 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/19 16:56:32 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"






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

int     hasWallAtSprite(float x, float y)
{

    int x0 = floor(x / TILE_SIZE);
    int y0 = floor(y / TILE_SIZE);
    if (x0 < 0 || x0 >= cub->map.rows  || y0 < 0 || y0 >= cub->map.columns) 
        return (0);
    else if (cub->map.map[x0][y0] == '2')
		return(1);
	return(0);
}

int     hasWallAt(float x, float y)
{

    int x0 = floor(x / TILE_SIZE);
    int y0 = floor(y / TILE_SIZE);
    if (x0 < 0 || x0 >= cub->map.rows  || y0 < 0 || y0 >= cub->map.columns) 
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

    if (!hasWallAt(player_x, player_y) && !hasWallAtSprite(player_x, player_y))
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

// static void			coord_sprites()
// {
// 	int	x;
// 	int	y;
// 	int	i;

// 	y = 0;
// 	i = 0;
// 	while (y < cub->map.rows)
// 	{
// 		x = 0;
// 		while (x < cub->map.columns)
// 		{
// 			if (cub->map.map[y][x] == '2')
// 			{
// 				cub->sprite[i].coord_x = x + 0.5;
// 				cub->sprite[i].coord_y = y + 0.5;
// 				i++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
// void				init_sprite()
// {
// 	int	i;

// 	// cub->north = set_texture(cub->map.north);
// 	// cub->south = set_texture(cub->map.south);
// 	// cub->east = set_texture(cub->map.east);
// 	// cub->west = set_texture(cub->map.west);
// 	if (!(cub->sprite = (t_sprite *)ft_calloc(sizeof(t_sprite), \
// 	cub->rc.nbr_sprites)))
// 		exit_game(cub, 6);
// 	i = -1;
// 	while (++i < cub->rc.nbr_sprites)
// 	{
// 		if (!(cub->sprite[i].img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
// 		cub->map.sprite, &cub->sprite[i].width, &cub->sprite[i].height)))
// 			exit_game(cub, 25);
// 		if (!(cub->sprite[i].get_data = \
// 		(int *)mlx_get_data_addr(cub->sprite[i].img_ptr, \
// 		&cub->sprite[i].bits_per_pixel, &cub->sprite[i].size_line, \
// 		&cub->sprite[i].endian)))
// 			exit_game(cub, 25);
// 	}
// 	coord_sprites();
// }

// static t_texture	set_texture(char *root_texture)
// {
// 	t_texture	texture;

// 	if (!(texture.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, root_texture, \
// 	&texture.width, &texture.height)))
// 		exit_game(cub, 24);
// 	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.img_ptr, \
// 	&texture.bits_per_pixel, &texture.size_line, &texture.endian)))
// 		exit_game(cub, 24);
// 	return (texture);
// }