/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/26 20:33:40 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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
			choose_flag(*format, argp);
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