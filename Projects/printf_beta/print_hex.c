/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:51:46 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/25 21:12:05 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(size_t integer)
{
	int length;

	length = 0;
	if (integer == 0)
		return (1);
	while (integer != 0)
	{
		integer /= 16;
		length++;
	}
	return (length);
}

void	print_space(t_flags *wpz, int *length, int *a)
{
	if (wpz->width.state && wpz->width.value > 0)
	{
		if (wpz->zero.state && wpz->zero.value > *length)
			*length = wpz->zero.value;
		while (wpz->width.value > *length)
			ft_putchar(' ' + 0 * wpz->width.value-- + 0 * (*a)++);
	}
}

void	print_zero(t_flags *wpz, int *length, int *a)
{
	if (wpz->zero.value < 0)
	{
		while (-wpz->zero.value > *length)
			ft_putchar(' ' + 0 * (*length)++ + 0 * (*a)++);
	}
}

void	print_kalifi(t_flags *wpz, int *length, int *a)
{
	if (wpz->zero.state && wpz->zero.value > *length)
		*length = wpz->zero.value;
	while (-wpz->width.value > *length)
		ft_putchar(' ' + 0 * (*a)++ + 0 * wpz->width.value++);
}

void	print_hex(char *format, va_list argp, t_flags wpz, int *a)
{
	unsigned int	u;
	int				length;

	u = va_arg(argp, unsigned int);
	length = cheeeck(*format == 'u' ? ft_nbrlen(u) : ft_hexlen(u), wpz, u);
	print_space(&wpz, &length, a);
	if (wpz.zero.state)
	{
		length = *format == 'u' ? ft_nbrlen(u) : ft_hexlen(u);
		while (wpz.zero.value > length)
			ft_putchar('0' + 0 * length++ + 0 * (*a)++);
	}
	length = (*format == 'u' ? ft_nbrlen(u) : ft_hexlen(u));
	if (!(wpz.prec.state && !wpz.prec.value && !u))
	{
		*format == 'u' ? ft_putnbr(u) : ft_hexatoi(u, *format - 23);
		(*a) += length;
	}
	if (wpz.width.state && wpz.width.value < 0)
	{
		length = cheeeck(*F == 'u' ? ft_nbrlen(u) : ft_hexlen(u), wpz, u);
		print_kalifi(&wpz, &length, a);
	}
}
