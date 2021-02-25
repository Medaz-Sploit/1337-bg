/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:57:08 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/25 14:46:43 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit(t_cub *cub)
{
	exit_game(cub, 0);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 0;
	if (keycode == S)
		cub->mv.down = 0;
	if (keycode == D)
		cub->mv.right = 0;
	if (keycode == A)
		cub->mv.left = 0;
	if (keycode == LEFT)
		cub->mv.rot_right = 0;
	if (keycode == RIGHT)
		cub->mv.rot_left = 0;
	if (keycode == ESC)
		key_exit(cub);
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 1; // walkDirection
	if (keycode == S)
		cub->mv.down = 1;
	if (keycode == D)
		cub->mv.right = 1; // turnDirection
	if (keycode == A)
		cub->mv.left = 1;
	if (keycode == LEFT)
		cub->mv.rot_right = 1;  // turnDirection
	if (keycode == RIGHT)
		cub->mv.rot_left = 1;
	return (0);
}
