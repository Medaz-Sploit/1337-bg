/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:57:08 by mazoukni          #+#    #+#             */
/*   Updated: 2021/01/30 14:02:47 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(t_cub *cub, int key_letter)
{
    if (key_letter == 'W')
        cub->mv.up = 1;
    if (key_letter == 'S')
        cub->mv.down = 1;
    if (key_letter == 'A')
        cub->mv.left = 1;
    if (key_letter == 'D')
        cub->mv.right = 1;
    if (key_letter == LEFT)
        cub->mv.rot_left = 1;
    if (key_letter == RIGHT)
        cub->mv.rot_right = 1;
}

int key_release(t_cub *cub, int key_letter)
{
    if (key_letter == 'W')
        cub->mv.up = 0;
    if (key_letter == 'S')
        cub->mv.down = 0;
    if (key_letter == 'A')
        cub->mv.left = 0;
    if (key_letter == 'D')
        cub->mv.right = 0;
    if (key_letter == LEFT)
        cub->mv.rot_left = 0;
    if (key_letter == RIGHT)
        cub->mv.rot_right = 0;
}

int key_out(t_cub *cub)
{
    exit_game(cub, 1);
}