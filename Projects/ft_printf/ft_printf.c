/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/07 19:51:16 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typdef struct s_data
{
	int precision = 0;
	int zero = 0;
	int star = 0;
	int moin = 0;
}t_data;

int flags(*format, t_data)
{
	struct t_data my_data;
	while (*format)
	{
		format++;
		if (*format != '*')
		{
			format++;
			my_data.star = 1;
		}
		if (*format != '0')
		{
			format++;
			my_data.zero = 1;
		}
		if (*format != '-')
		{
			
		}
}


int ft_printf(const char *format, ...)
{
	va_list argp;
	int d;
	char *p;
	va_start(argp, format);
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
			if (*format == '%')
			{
				format++;
				ft_putchar('%');
			}
			if (*format >= '0' && *format <=)
		}
		ft_putchar(*format);
		format++;
	}
	va_end(argp);
	return (1);
}

int main(void)
{
	//int m = 1546664;
	//int c  = 13;
	//char l[] = "nice work bro";
	printf("this is a %d sign and this one %d\n", -2035065302, 15);
	ft_printf("this is a %d sign and this one %d\n", -2035065302, 15);
	return (0);
}