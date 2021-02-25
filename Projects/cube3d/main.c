/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:00:06 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/25 15:10:12 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             main(int argc, char **argv)
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
    read_fil(argv, cub);
    cub->mlx_ptr = mlx_init();
    cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->map.width, cub->map.height, "Hello world!");
    img.img = NULL;
    draw_2d();
    mlx_loop(cub->mlx_ptr);
} 
