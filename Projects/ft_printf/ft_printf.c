/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/12 04:08:24 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_data{
	int moin;
	int zero;
	int precision;
	int star;
}t_data;

void flags(int *format, t_data my_data)
{
	if (*format == '*')
	{
		format++;
		my_data.star = 1;
	}
	if (*format == '0')
	{
		format++;
		my_data.zero = 1;
	}
	if (*format == '-')
	{
		format++;
		my_data.moin = 1;
	}
	if (*format == '.')
	{
		format++;
		my_data.precision = 1;
	}
}



int ft_printf(const char *format, ...) // handle all convertions such as `p` `i` `u` `x` `X` `%`
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
			if (*format == 'd' || *format == 'i')
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
	//int m = 1546664;
	int c  = 762862;
	//char l[] = "nice work bro";
	printf("Bla Bla %c\n", 0);
	ft_printf("Bla Bla %c\n", 0);
	ft_dectohex(c);
	return (0);
}