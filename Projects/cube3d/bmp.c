/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:45:59 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/31 23:16:12 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_bmp(t_bmp *bmp, t_cub *g_cub)
{
	int	i;
	int	j;

	ft_bzero(bmp->zero, 3);
	i = g_cub->map.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < g_cub->map.width)
		{
			bmp->color = g_dst[i * g_cub->map.width + j];
			write(bmp->fd, &bmp->color, 3);
			j++;
		}
		if (bmp->padding > 0)
			write(bmp->fd, &bmp->zero, bmp->padding);
		i--;
	}
}

static void	header(t_bmp *bmp, t_cub *g_cub)
{
	ft_bzero(bmp->header, 54);
	bmp->size = 54 + 3 * (g_cub->map.width + bmp->padding) * g_cub->map.height;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[2] = (bmp->size);
	bmp->header[3] = (bmp->size >> 8);
	bmp->header[4] = (bmp->size >> 16);
	bmp->header[5] = (bmp->size >> 24);
	bmp->header[10] = 54;
	bmp->header[14] = 40;
	bmp->header[18] = (g_cub->map.width);
	bmp->header[19] = (g_cub->map.width >> 8);
	bmp->header[20] = (g_cub->map.width >> 16);
	bmp->header[21] = (g_cub->map.width >> 24);
	bmp->header[22] = (g_cub->map.height);
	bmp->header[23] = (g_cub->map.height >> 8);
	bmp->header[24] = (g_cub->map.height >> 16);
	bmp->header[25] = (g_cub->map.height >> 24);
	bmp->header[26] = 1;
	bmp->header[28] = 24;
	write(bmp->fd, &bmp->header, 54);
}

void	bmp(t_cub *g_cub)
{
	t_bmp	*bmp;

	bmp = (t_bmp *)malloc(sizeof(t_bmp));
	if (!bmp)
		exit_game(g_cub, 6);
	ft_bzero(bmp, sizeof(t_bmp));
	bmp->padding = g_cub->map.width % 4;
	bmp->fd = open("cub3d.bmp", O_CREAT | O_RDWR, 0644);
	if (bmp->fd < 0)
	{
		ft_putstr_fd("Problem in function open(bmp.c)\n", 1);
		exit_game(g_cub, 0);
	}
	header(bmp, g_cub);
	render_bmp(bmp, g_cub);
	close(bmp->fd);
	free(bmp);
	ft_putstr_fd("Your cub3d.bmp is ready\n", 1);
	exit_game(g_cub, 0);
}

void	exit_map(t_cub *g_cub)
{
	int	i;

	i = 0;
	if (g_cub->sprite)
	{
		while (i < g_cub->rc.nbr_sprites)
		{
			if (g_cub->sprite[i].get_data)
				mlx_destroy_image(g_cub->mlx_ptr, g_cub->sprite[i].img_ptr);
			if (g_cub->mlx_ptr && g_cub->win_ptr)
				mlx_clear_window(g_cub->mlx_ptr, g_cub->win_ptr);
			i++;
		}
	}
	if (g_cub->sprite)
		free(g_cub->sprite);
	i = 0;
	if (g_cub->map.tmp)
		free(g_cub->map.tmp);
	if (g_cub->map.map)
	{
		while (i <= g_cub->map.rows)
			free(g_cub->map.map[i++]);
	}
	free(g_cub->map.map);
}

int	exit_game(t_cub *g_cub, int e)
{
	if (e > 0 && e < 34)
		errors(e);
	else if (e == 35)
		ft_putstr_fd("Error\nOuch Homie (°^°) u gotta a lot of sprites T.T\n", 1);
	exit_map(g_cub);
	free(g_cub->mlx_ptr);
	free(g_cub->win_ptr);
	free(g_cub->north.img_ptr);
	free(g_cub->south.img_ptr);
	free(g_cub->east.img_ptr);
	free(g_cub->west.img_ptr);
	free(g_cub->map.north);
	free(g_cub->map.south);
	free(g_cub->map.east);
	free(g_cub->map.west);
	free(g_cub->map.sprite);
	exit(0);
	return (0);
}
