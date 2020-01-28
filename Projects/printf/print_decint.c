/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:55:47 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/27 19:03:38 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_nbrlen(int integer)
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
	return length;
}

void print_decint(char *format, va_list argp, t_flags wpz, int *a)
{
	long integer;
	int length;
	int sign;
	
	sign = 0;
	integer = va_arg(argp, int);        // %
	length = *format == 'c' ? 1 : ft_nbrlen(integer);
	if (wpz.width.state && wpz.width.value > 0)
	{
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (wpz.width.value > length)
			ft_putchar(' ' + 0 * wpz.width.value-- + 0 * (*a)++);
	}
	if (integer < 0)
	{
		sign = 1;
		ft_putchar('-' + 0 * (*a)++);
		integer *= -1;
	}
	if (wpz.zero.state)
	{
		length = *format == 'c' ? 1 : ft_nbrlen(integer) + sign;
		if (wpz.zero.value < 0)
		{
			while (length != 0)
				ft_putchar(' ' + 0 * length-- + 0 * (*a)++);
		}
		// printf("vv %d\n", wpz.zero.value);
		while (wpz.zero.value > length) // %0-5d, -42
			ft_putchar('0' + 0 * length++ + 0 * (*a)++);
	}
	if (*format == 'c')
		ft_putchar(integer + 0 * (*a)++);
	
	ft_putnbr(integer + 0 * (*a += ft_nbrlen(integer)));
	if (wpz.width.state && wpz.width.value < 0)
	{
		length = *format == 'c' ? 1 : ft_nbrlen(integer) + sign;
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (-wpz.width.value > length)
			ft_putchar(' ' + 0 * (*a)++ + 0 * wpz.width.value++);
	}
}