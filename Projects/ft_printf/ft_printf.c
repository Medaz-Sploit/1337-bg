/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/13 00:39:35 by mazoukni         ###   ########.fr       */
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



int ft_printf(const char *format, ...) // handle all convertions such as `p` `i` `u` `x` `X` `%`  %[flags][min field width][precision][length]conversion specifier
{
	
	va_list argp;
	size_t d;
	char *p;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				ft_putstr(ft_itoa(va_arg(argp, int)));
				format++;
			}
			if (*format == 's')
			{
				p = va_arg(argp, char*);
				ft_putstr(p);
				format++;
			}
			if (*format == 'c')
			{
				ft_putchar(va_arg(argp, int));
				format++;
			}
			if (*format == 'x')
			{
				ft_dectohex(*format, va_arg(argp, unsigned int));
				format++;
			}
			if (*format == 'p')
			{
				ft_putstr("0x");
				d = va_arg(argp, size_t);
				ft_dectohex(*format , d);
				format++;
			}
			if (*format == 'X')
			{
				ft_dectohex(*format, va_arg(argp, unsigned int));
				format++;
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
	//int c  = 762862;
	char l[] = "nice  jjjdfsdfgskhwor";
	printf("Bla Bla %p\n",l);
	ft_printf("Bla Bla %p\n", l);
	return (0);
}