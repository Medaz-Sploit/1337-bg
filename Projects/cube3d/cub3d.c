/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:29:59 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/23 01:05:53 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 
int main(int argc, char** argv)
{
	t_cub *cub;
	int len;

	if(!(cub = (t_cub *)malloc(sizeof(t_cub))))
		exit_game(cub, 1);
	ft_bzero(cub, sizeof(t_cub));
	if (argc < 2 && argc > 3)
		exit_game(cub, 6);
	else if (!(len = ft_strlen(argv[1] - 4))
		exit_game(cub, 4);
	else if (ft_strncmp(argv[1] + len, ".cub", 4))
		exit_game(cub, 3);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 6))
			cub->save = 1;
		else 
			exit_game(cub, 11);
	}
	read_file(argv[1], cub);
}
