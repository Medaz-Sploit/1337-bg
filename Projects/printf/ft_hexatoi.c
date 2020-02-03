/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:37:39 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/02 00:33:30 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexatoi(size_t u, char a)
{
	char	tab[16];
	int		i;
	size_t	div;
	char	c;

	i = -1;
	while (++i < 16)
		tab[i] = i + (i > 9 ? a - 10 : '0');
	div = 1;
	while (u / div > 15)
		div *= 16;
	while (div)
	{
		c = tab[(u / div) % 16];
		write(1, &c, 1);
		div /= 16;		
	}
}