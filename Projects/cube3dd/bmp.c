/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:45:59 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/26 16:32:02 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_bmp(t_bmp *bmp, t_cub *cub)
{
	int	i;
	int	j;

	ft_bzero(bmp->zero, 3);
	i = cub->map.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < cub->map.width)
		{
			bmp->color = dst[i * cub->map.width + j];
			write(bmp->fd, &bmp->color, 3);
			j++;
		}
		if (bmp->padding > 0)
			write(bmp->fd, &bmp->zero, bmp->padding);
		i--;
	}
}

static void	header(t_bmp *bmp, t_cub *cub)
{
	ft_bzero(bmp->header, 54);
	bmp->size = 54 + 3 * (cub->map.width + bmp->padding) * cub->map.height;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[2] = (bmp->size);
	bmp->header[3] = (bmp->size >> 8);
	bmp->header[4] = (bmp->size >> 16);
	bmp->header[5] = (bmp->size >> 24);
	bmp->header[10] = 54;
	bmp->header[14] = 40;
	bmp->header[18] = (cub->map.width);
	bmp->header[19] = (cub->map.width >> 8);
	bmp->header[20] = (cub->map.width >> 16);
	bmp->header[21] = (cub->map.width >> 24);
	bmp->header[22] = (cub->map.height);
	bmp->header[23] = (cub->map.height >> 8);
	bmp->header[24] = (cub->map.height >> 16);
	bmp->header[25] = (cub->map.height >> 24);
	bmp->header[26] = 1;
	bmp->header[28] = 24;
	write(bmp->fd, &bmp->header, 54);
}

void		bmp(t_cub *cub)
{
	t_bmp	*bmp;

	if (!(bmp = (t_bmp *)malloc(sizeof(t_bmp))))
		exit_game(cub, 6);
	ft_bzero(bmp, sizeof(t_bmp));
	bmp->padding = cub->map.width % 4;
	bmp->fd = open("cub3d.bmp", O_CREAT | O_RDWR, 0644);
	if (bmp->fd < 0)
	{
		ft_putstr_fd("Problem in function open(bmp.c)\n", 1);
		exit_game(cub, 0);
	}
	header(bmp, cub);
	render_bmp(bmp, cub);
	close(bmp->fd);
	free(bmp);
	ft_putstr_fd("Your cub3d.bmp is ready\n", 1);
	exit_game(cub, 0);
}