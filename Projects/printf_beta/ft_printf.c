/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/28 11:56:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list argp;
	int		a;

	a = 0;
	if (format)
	{
		va_start(argp, format);
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				format = choose_flag((char*)format, argp, &a);
			}
			else
				ft_putchar(*(format++));
			a++;
		}
		va_end(argp);
	}
	return (a);
}
