/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:44:55 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/22 18:30:15 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zeros(t_flags *wpz, int *length, int *a)
{
	while (wpz->zero.value > *length)
		ft_putchar('0' + 0 * (*length)++ + 0 * (*a)++);
}

void	check_neg(long *integer, int *sign)
{
	if (*integer < 0)
	{
		*sign = 1;
		*integer *= -1;
	}
}

void	utils(char *format, t_flags *wpz, long *integer, int *a)
{
	if (*format == 'c')
		ft_putchar(*integer + 0 * (*a)++);
	else if (!(wpz->prec.state && wpz->prec.value == 0 && *integer == 0))
		ft_putnbr(*integer + 0 * (*a += ft_nbrlen(*integer)));
}
