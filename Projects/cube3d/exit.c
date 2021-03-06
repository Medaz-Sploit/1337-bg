/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 07:21:17 by mazoukni          #+#    #+#             */
/*   Updated: 2021/03/30 07:25:17 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_fuck(void)
{
	exit(0);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

static void	errors_identifiers(int e)
{
	if (e == 23)
		ft_putstr_fd("Error\nResolution must be only numbers\n", 1);
	else if (e == 24)
		ft_putstr_fd("Error\nWrong texture\n", 1);
	else if (e == 25)
		ft_putstr_fd("Error\nInvalid sprite texture\n", 1);
	else if (e == 26)
		ft_putstr_fd("Error\nInvalid character in RGB color\n", 1);
	else if (e == 27)
		ft_putstr_fd("Error\nValue RGB range is 0-255\n", 1);
	else if (e == 28)
		ft_putstr_fd("Error\nNo coma between RGB color\n", 1);
	else if (e == 29)
		ft_putstr_fd("Error\nMissing edges on the map\n", 1);
	else if (e == 30)
		ft_putstr_fd("Error\nMap is not closed on the north side\n", 1);
	else if (e == 31)
		ft_putstr_fd("Error\nMap is not closed on the south side\n", 1);
	else if (e == 32)
		ft_putstr_fd("Error\nMap is not closed on the west side\n", 1);
	else if (e == 33)
		ft_putstr_fd("Error\nMap is not closed on the east side\n", 1);
}

static void	errors_defined(int e)
{
	if (e > 22)
		errors_identifiers(e);
	else if (e == 12)
		ft_putstr_fd("Error\nMissing Identifier before map\n", 1);
	else if (e == 13)
		ft_putstr_fd("Error\nResolution already defined\n", 1);
	else if (e == 14)
		ft_putstr_fd("Error\nNorth texture already defined\n", 1);
	else if (e == 15)
		ft_putstr_fd("Error\nSouth texture already defined\n", 1);
	else if (e == 16)
		ft_putstr_fd("Error\nEast textures already defined\n", 1);
	else if (e == 17)
		ft_putstr_fd("Error\nWest textures already defined\n", 1);
	else if (e == 18)
		ft_putstr_fd("Error\nSprite texture already defined\n", 1);
	else if (e == 19)
		ft_putstr_fd("Error\nFloor color is already defined\n", 1);
	else if (e == 20)
		ft_putstr_fd("Error\nCeiling color is already defined\n", 1);
	else if (e == 21)
		ft_putstr_fd("Error\nPlayer position already defined\n", 1);
	else if (e == 22)
		ft_putstr_fd("Error\nNo player position defined\n", 1);
}

void	errors(int e)
{
	if (e > 11)
		errors_defined(e);
	else if (e == 1)
		ft_putstr_fd("Error\nNumber of arguments incorrect\n", 1);
	else if (e == 2)
		ft_putstr_fd("Error\nThe file must have a name\n", 1);
	else if (e == 3)
		ft_putstr_fd("Error\nThe file must be .cub\n", 1);
	else if (e == 4)
		ft_putstr_fd("Error\nSecond argument must be --save\n", 1);
	else if (e == 5)
		ft_putstr_fd("Error\nmlx problem\n", 1);
	else if (e == 6)
		ft_putstr_fd("Error\nMemory allocation problem\n", 1);
	else if (e == 7)
		ft_putstr_fd("Error\nThis map doesn't exist\n", 1);
	else if (e == 8)
		ft_putstr_fd("Error\nConfiguration file is empty\n", 1);
	else if (e == 9)
		ft_putstr_fd("Error\nNo map in configuration file\n", 1);
	else if (e == 10)
		ft_putstr_fd("Error\nInvalid line in configuration file\n", 1);
	else if (e == 11)
		ft_putstr_fd("Error\nInvalid character in the map\n", 1);
}
