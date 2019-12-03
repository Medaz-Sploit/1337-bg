/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/03 20:41:51 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list argp;
	int d;
	char *p;
	va_start(argp, format);
	//va_arg(argp, int);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				format++;
				d = va_arg(argp, int);
				ft_putstr(ft_itoa(d));
			}
			if (*format == 's')
			{
				format++;
				p = va_arg(argp, char*);
				ft_putstr(p);
			}
			if (*format == 'c')
			{
				format++;
				d = va_arg(argp, int);
				ft_putchar(d);
			}
		}
		ft_putchar(*format);
		format++;
	}
	return (1);
}

int main(void)
{
	int m = 1546664;
	//int c  = 13;
	//char l[] = "nice work bro";
	printf("%d\n", m);
	ft_printf("%d\n", m);
	return (0);
}