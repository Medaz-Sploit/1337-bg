/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/01 19:32:40 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *format, ...) 
{
	
	va_list argp;
	int a;

	a = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format != '%')
				format = choose_flag((char*)format, argp, &a);
		}
		if (!(*format))
			break ;
		ft_putchar(*(format++));
		a++;
	}
	return (1);
}

/*int main(void)
{
	ft_printf("%0*.*d|\n", -10, -5, 42);
	printf("%0*.*d|\n",-10,  -5, 42);
	return (0);
}*/

       