/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:29:59 by mazoukni          #+#    #+#             */
/*   Updated: 2020/03/11 16:46:16 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
	
}

get_next_line();

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	int i = 240;
	int j = 240;
	while (i < 290)
		mlx_pixel_put(mlx_ptr, win_ptr, i++, j, 0xFCAFFF);
	mlx_loop(mlx_ptr);
}
