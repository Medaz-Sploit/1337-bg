/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:57:08 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/31 22:45:12 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit(void)
{
	exit_game(g_cub, 0);
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == W)
		g_cub->walkdirection = 0;
	if (keycode == S)
		g_cub->walkdirection = 0;
	if (keycode == D)
		g_cub->turndirection = 0;
	if (keycode == A)
		g_cub->turndirection = 0;
	if (keycode == LEFT)
		g_cub->turndirection = 0;
	if (keycode == RIGHT)
		g_cub->turndirection = 0;
	if (keycode == UP)
		g_cub->walkdirection = 0;
	if (keycode == DOWN)
		g_cub->walkdirection = 0;
	if (keycode == 259 || keycode == 260)
		g_cub->turndirection = 0;
	if (keycode == 259 || keycode == 260)
		g_cub->walkdirection = 0;
	if (keycode == ESC)
		key_exit();
	return (0);
}

int	key_press(int keycode)
{
	if (keycode == W)
		g_cub->walkdirection = 1;
	if (keycode == S)
		g_cub->walkdirection = -1;
	if (keycode == D)
		g_cub->turndirection = 1;
	if (keycode == A)
		g_cub->turndirection = -1;
	if (keycode == LEFT)
		g_cub->turndirection = -1;
	if (keycode == RIGHT)
		g_cub->turndirection = 1;
	if (keycode == UP)
		g_cub->walkdirection = 1;
	if (keycode == DOWN)
		g_cub->walkdirection = -1;
	return (0);
}
