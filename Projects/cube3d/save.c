/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:45:27 by mazoukni          #+#    #+#             */
/*   Updated: 2021/01/27 03:46:09 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*save_texture(char *line, int i)
{
	char *texture;
    
	while (ft_isalpha(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	texture = ft_strdup(&line[i]);
	return(texture);
}