/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:20:51 by mazoukni          #+#    #+#             */
/*   Updated: 2021/01/31 01:28:00 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "get_next_line/get_next_line.h"

# define TILE_SIZE 32
# define PI 3.14
# define FOV_ANGLE (60 * (PI / 180))
# define MAP_NUM_ROWS 14
# define MAP_NUM_COLS 30
# define WINDOW_WIDTH ( MAP_NUM_COLS * TILE_SIZE )
# define WINDOW_HEIGHT ( MAP_NUM_ROWS * TILE_SIZE )
# define W 13
# define S 1
# define D 2
# define A 0
# define RIGHT 124
# define LEFT 123
# define ESC 53

typedef struct  s_rgb {
    
}               t_rgb;

typedef struct  s_error {
    int 
    
}               t_error;

typedef struct  s_map {
    int R_X;
    int R_Y;
    char *NO_Path;
    char *SO_Path;
    char *WE_Path;
    char *EA_Path;
    char *S_Path;
    int floor;
    int ceiling;
    struct t_rgb;
}               t_map;

typedef struct  s_env {
    int fd;
    int line_num;
    int line_len;
    char* line;
    char *tmp;
}               t_env;

typedef struct  s_movement {
    int up;
    int down;
    int left;
    int right;
    int rot_left;
    int rot_right;
}               t_movement;

typedef struct  s_cub {
    bool R;
    bool NO;
    bool SO;
    bool WE;
    bool EA;
    bool S;
    bool F;
    bool C;
    t_map map;
    t_env env;
    t_movement mv;
    int save;
}               t_cub;

#endif