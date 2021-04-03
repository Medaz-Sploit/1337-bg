/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:00:06 by mazoukni          #+#    #+#             */
/*   Updated: 2021/04/03 01:03:04 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	if (x < g_cub->map.width && y < g_cub->map.height && x >= 0 && y >= 0)
		g_dst[y * (int)g_cub->map.width + x] = color;
}

int	main(int argc, char **argv)
{
	int	len;

	g_cub = (t_cub *)malloc(sizeof(t_cub));
	if (!g_cub)
		exit_game(g_cub, 6);
	ft_bzero(g_cub, sizeof(t_cub));
	len = ft_strlen(argv[1]) - 4;
	if (argc < 2 || argc > 3)
		exit_game(g_cub, 1);
	else if (!len)
		exit_game(g_cub, 2);
	else if (ft_strncmp(argv[1] + len, ".cub", 4))
		exit_game(g_cub, 3);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 6) && ft_strlen(argv[2]) == 6)
			g_cub->save = 1;
		else
			exit_game(g_cub, 4);
	}
	call_me(argv);
}

void	init(char **argv)
{
	g_cub->rotationangle = M_PI / 2;
	g_cub->turndirection = 0;
	g_cub->rotationspeed = 5 * (M_PI / 180);
	g_cub->walkdirection = 0;
	g_cub->movespeed = 5.0;
	g_cub->radius = 3;
	read_fil(argv, g_cub);
	g_cub->mlx_ptr = mlx_init();
	g_cub->win_ptr = mlx_new_window(g_cub->mlx_ptr, g_cub->map.width, \
					g_cub->map.height, "Hello world!");
	g_img.img = NULL;

}

void	call_me(char **argv)
{
	init(argv);
	player_pos();
	init_texture();
	init_sprites();
	mlx_hook(g_cub->win_ptr, 2, 0, key_press, "lll");
	mlx_hook(g_cub->win_ptr, 3, 0, key_release, "lll");
	mlx_loop_hook(g_cub->mlx_ptr, &update, "");
	mlx_hook(g_cub->win_ptr, 17, 1L << 5, exit_fuck, "lll");
	mlx_loop(g_cub->mlx_ptr);
}

