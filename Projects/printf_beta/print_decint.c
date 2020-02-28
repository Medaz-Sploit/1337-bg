/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:55:47 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/25 21:11:28 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(long integer)
{
	int length;

	length = 0;
	if (integer == 0)
		return (1);
	if (integer < 0)
		length++;
	while (integer != 0)
	{
		integer /= 10;
		length++;
	}
	return (length);
}

void	print_spaace(t_flags *wpz, int *length, int *sign, int *a)
{
	if (wpz->width.state && wpz->width.value > 0)
	{
		*length = !*length && wpz->prec.state && wpz->width.state &&
		wpz->prec.value < 0 ? 1 : *length;
		if (wpz->zero.state && wpz->zero.value > *length)
			*length = wpz->zero.value +
			(wpz->prec.state && wpz->prec.value > -1 ? *sign : 0);
		while (wpz->width.value > *length)
			ft_putchar(' ' + 0 * wpz->width.value-- + 0 * (*a)++);
	}
}

void	print_espace(t_flags *wpz, int *length, int *a)
{
	if (wpz->zero.value < 0)
	{
		if (!(wpz->prec.state))
			while (-wpz->zero.value > *length)
				ft_putchar(' ' + 0 * (*length)++ + 0 * (*a)++);
	}
}

void	print_zeero(t_flags *wpz, int *length, int *sign, int *a)
{
	if (wpz->zero.state && wpz->zero.value > *length)
		*length = wpz->zero.value;
	if ((wpz->prec.state && wpz->prec.value < 0) ||
	(wpz->width.value < 0 && *sign == 1))
		*length += *sign;
	while (-wpz->width.value > *length)
		ft_putchar(' ' + 0 * (*a)++ + 0 * wpz->width.value++);
}

void	print_decint(char *format, va_list argp, t_flags wpz, int *a)
{
	long	integer;
	int		length;
	int		sign;

	sign = 0;
	integer = va_arg(argp, int);
	length = *format == 'c' ? 1 : ft_nbrlen(I) - 1 * (!I && wpz.prec.state);
	check_neg(&integer, &sign);
	print_spaace(&wpz, &length, &sign, a);
	if (sign == 1 && (length = 1) == 1)
		ft_putchar('-' + 0 * (*a)++);
	if (wpz.zero.state)
	{
		if (*format != 'c')
			length = ft_nbrlen(integer) +
			(wpz.prec.state && wpz.prec.value > -1 ? 0 : sign);
		print_zeros(&wpz, &length, a);
	}
	utils(format, &wpz, &integer, a);
	print_espace(&wpz, &length, a);
	if (wpz.width.state && wpz.width.value < 0)
	{
		LEN = *F == 'c' ? 1 : cheeeck(ft_nbrlen(I), wpz, I);
		print_zeero(&wpz, &length, &sign, a);
	}
}
