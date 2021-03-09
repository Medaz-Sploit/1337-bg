/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:57:08 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/07 01:48:05 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit()
{
	exit_game(cub, 0);
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == W)
		cub->walkdirection = 0;
	if (keycode == S)
		cub->walkdirection = 0;
	if (keycode == D)
		cub->turndirection = 0;
	if (keycode == A)
		cub->turndirection = 0;
	if (keycode == LEFT)
		cub->turndirection = 0;
	if (keycode == RIGHT)
		cub->turndirection = 0;
	if (keycode == UP)
		cub->walkdirection = 0;
	if (keycode == DOWN)
		cub->walkdirection = 0;
	if (keycode == ESC)
		key_exit();
	return (0);
}

int	key_press(int keycode)
{
	if (keycode == W)
		cub->walkdirection = 1; // walkDirection
	if (keycode == S)
		cub->walkdirection = -1;
	if (keycode == D)
		cub->turndirection = 1; // turnDirection
	if (keycode == A)
		cub->turndirection = -1;
	if (keycode == LEFT)
		cub->turndirection = -1;  // turnDirection
	if (keycode == RIGHT)
		cub->turndirection = 1;
	if (keycode == UP)
		cub->walkdirection = 1;
	if (keycode == DOWN)
		cub->walkdirection = -1;
	return (0);
}
