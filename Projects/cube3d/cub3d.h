/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:20:51 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/25 15:08:45 by mazoukni         ###   ########.fr       */
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
# include "libft/libft.h"

# define WALL_STRIP_WIDTH 1
# define TILE_SIZE 20
# define PI 3.14
# define FOV_ANGLE (60 * (M_PI / 180))
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 34
# define WINDOW_WIDTH ( MAP_NUM_COLS * TILE_SIZE )
# define WINDOW_HEIGHT ( MAP_NUM_ROWS * TILE_SIZE )
# define NUM_RAYS  ( WINDOW_WIDTH / WALL_STRIP_WIDTH )
# define W 13
# define S 1
# define D 2
# define A 0
# define RIGHT 124
# define LEFT 123
# define ESC 53


typedef struct		s_bmp
{
	unsigned char	header[54];
	unsigned char	zero[3];
	int				size;
	int				padding;
	int				fd;
	int				color;
}					t_bmp;

typedef struct		s_identifiers
{
	int				r;
	int				no;
	int				so;
	int				ea;
	int				we;
	int				s;
	int				f;
	int				c;
	int				m;
	int				player;
}					t_identifiers;

typedef struct		s_sprite
{
	int				order;
	double			distance;
	double			coord_x;
	double			coord_y;
	void			*img_ptr;
	int				*get_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				color;
}					t_sprite;

typedef struct		s_texture
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_colors
{
	int				roof;
	int				floor;
	int				north;
	int				south;
	int				east;
	int				west;
	int				wall;
}					t_colors;

typedef struct		s_movement
{
	int				up;
	int				down;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
	double			olddir_x;
	double			oldplane_x;
	double			rot_speed;
}					t_movement;

typedef struct		s_raysprite
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				height;
	int				width;
	double			*dist_wall;
}					t_raysprite;

typedef struct		s_raycasting
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plan_x;
	double			plan_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				nbr_sprites;
}					t_raycasting;

typedef struct		s_map
{
	char			**map;
	char			*tmp;
	int				rows;
	int				columns;
	int				width;
	int				height;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
	int				floor;
	int				ceiling;
	char			orientation;
}					t_map;

typedef struct		s_cub
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*new_image;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				save;
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
	float hitWallColor;

	float isRayFacingDown;
	float isRayFacingUp;

	float isRayFacingRight;
	float isRayFacingLeft;
	t_map			map;
	t_raycasting	rc;
	t_raysprite		rs;
	t_movement		mv;
	t_colors		color;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_sprite		*sprite;
	t_identifiers	id;
}					t_cub;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;
float rayAngle = normalizeAngle(rayAngle);
float wallHitX = 0;
float wallHitY = 0;
float distance = 0;
bool wasHitVertical = false;
float hitWallColor = 0;

float isRayFacingDown = rayAngle > 0 && rayAngle < M_PI;
float isRayFacingUp = !isRayFacingDown;

float isRayFacingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
float isRayFacingLeft = !isRayFacingRight;
t_data img;
t_cub   *cub;
int					read_fil(char **argv, t_cub *cub);
void				check_identifier(t_cub *cub, char *line);
void				save_res(t_cub *cub, char *line, int i);
char				*save_texture(char *line, int i);
int					save_color(t_cub *cub, char *line, int i);
void				check_color(t_cub *cub, char *line, int i);
void				check_map(t_cub *cub);
void				check_file(t_cub *cub);
void				save_map(t_cub *cub);
int					exit_game(t_cub *cub, int e);
void                my_mlx_pixel_put(int x, int y, int color);
int                 draw_2d();
int	                ft_isspace(int c);

#endif