/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:51:46 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/06 14:52:29 by mazoukni         ###   ########.fr       */
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
	return length;
}

void	print_hex(char *format, va_list argp, t_flags wpz, int *a)
{
	unsigned int	u;
	int				length;

	u = va_arg(argp, unsigned int);
	length = *format == 'u' ? ft_nbrlen(u) : ft_hexlen(u);
	if (wpz.width.state && wpz.width.value > 0)
	{
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (wpz.width.value > length)
			ft_putchar(' ' + 0 * wpz.width.value-- + 0 * (*a)++);
	}
	if (wpz.zero.state)
	{
		length = *format == 'u' ? ft_nbrlen(u) : ft_hexlen(u);
		while (wpz.zero.value > length)
			ft_putchar('0' + 0 * length++ + 0 * (*a)++);
	}
	length = *format == 'u' ? ft_nbrlen(u) : ft_hexlen(u);
	if (*format == 'u')
		ft_putnbr(u + 0 * (*a += length));
	else
		ft_hexatoi(u, *format - 23 + 0 * (*a += length));
	if (wpz.zero.value < 0)
	{
		while (-wpz.zero.value > length)
			ft_putchar(' ' + 0 * length++ + 0 * (*a)++);
	}
	if (wpz.width.state && wpz.width.value < 0)
	{
		length = *format == 'u' ? ft_nbrlen(u) : ft_hexlen(u);
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (-wpz.width.value > length)
			ft_putchar(' ' + 0 * (*a)++ + 0 * wpz.width.value++);
	}
}
