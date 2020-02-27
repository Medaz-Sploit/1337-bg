/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:57:49 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/07 18:58:01 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(va_list argp, t_flags wpz, int *a)
{
	size_t	u;
	int		length;

	u = va_arg(argp, size_t);
	length = ft_hexlen(u) + 2;
	if (wpz.width.state && wpz.width.value > 0)
	{
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (wpz.width.value > length)
			ft_putchar(' ' + 0 * wpz.width.value-- + 0 * (*a)++);
	}
	if (wpz.zero.state)
	{
		length = ft_hexlen(u) + 2;
		while (wpz.zero.value > length)
			ft_putchar('0' + 0 * length++ + 0 * (*a)++);
	}
	length = ft_hexlen(u) + 2;
	ft_putstr("0x");
	ft_hexatoi(u, 'a' + 0 * (*a += length));
	if (wpz.zero.state && wpz.zero.value < 0)
	{
		while (-wpz.zero.value > length)
			ft_putchar(' ' + 0 * length++ + 0 * (*a)++);
	}
	if (wpz.width.state && wpz.width.value < 0)
	{
		length = ft_hexlen(u) + 2;
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (-wpz.width.value > length)
			ft_putchar(' ' + 0 * (*a)++ + 0 * wpz.width.value++);
	}
}
