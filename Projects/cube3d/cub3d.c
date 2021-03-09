/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:00:06 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/07 21:34:22 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int             key_hook(int keycode)
{
    printf("Keycode is:\t %d\n", keycode);
    return(0);
}

void            my_mlx_pixel_put(int x, int y, int color)
{
    int		*dst;

	dst = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (x < cub->map.width && y < cub->map.height && x >= 0 && y >= 0)
		dst[y * (int)cub->map.width + x] = color;
}

int             main(int argc, char **argv)
{ 
      
    int		len;

    if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		exit_game(cub, 6);
	ft_bzero(cub, sizeof(t_cub));
	if (argc < 2 || argc > 3)
		exit_game(cub, 1);
	else if (!(len = ft_strlen(argv[1]) - 4))
		exit_game(cub, 2);
	else if (ft_strncmp(argv[1] + len, ".cub", 4))
		exit_game(cub, 3);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 6))
			cub->save = 1;
		else
			exit_game(cub, 4);
	}
    cub->rotationangle = M_PI / 2;
    cub->turndirection = 0;
    cub->rotationspeed = 2 * (M_PI / 180);
    cub->walkdirection = 0;
    cub->movespeed = 2.0;
    cub->radius = 3;
    read_fil(argv, cub);
    cub->mlx_ptr = mlx_init();
    cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->map.width, cub->map.height, "Hello world!");
    img.img = NULL;
    player_pos();
    //mlx_key_hook(cub->win_ptr, key_hook, &cub);
    mlx_hook(cub->win_ptr, 2, 0, key_press, "lll");
	mlx_hook(cub->win_ptr, 3, 0, key_release, "lll");
    mlx_loop_hook(cub->mlx_ptr, &update, "");
    mlx_loop(cub->mlx_ptr);
} 
