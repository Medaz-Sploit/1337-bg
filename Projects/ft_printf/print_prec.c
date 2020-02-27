/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:14:39 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/22 18:45:04 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prec(t_flags wpz, int *a)
{
	if (wpz.width.state && wpz.width.value > 1)
	{
		if (wpz.zero.state)
		{
			while (wpz.zero.value > 1)
				ft_putchar('0' + 0 * wpz.zero.value-- + 0 * (*a)++);
			ft_putchar('%' + 0 * (*a)++);
		}
		else
		{
			while (wpz.width.value > 1)
				ft_putchar(' ' + 0 * wpz.width.value-- + 0 * (*a)++);
			ft_putchar('%' + 0 * (*a)++);
		}
	}
	else if (wpz.width.state && wpz.width.value < 0)
	{
		ft_putchar('%' + 0 * (*a)++);
		while (-wpz.width.value > 1)
			ft_putchar(' ' + 0 * wpz.width.value++ + 0 * (*a)++);
	}
	else
		ft_putchar('%' + 0 * (*a)++);
}
