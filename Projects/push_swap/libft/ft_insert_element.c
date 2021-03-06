/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 00:09:34 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/25 01:30:16 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insert_element(char *str, char **tab, int i, char c)
{
	int		j;

	j = 0;
	while (str[j] != c && str[j] != '\0')
	{
		tab[i][j] = str[j];
		j++;
	}
	tab[i][j] = '\0';
}
