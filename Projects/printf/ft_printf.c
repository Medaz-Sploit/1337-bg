/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/26 18:29:21 by mazoukni         ###   ########.fr       */
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
	printf("%*.4d|\n",5, 454);
	ft_printf("%*.4d|\n",5, 454);
	return (0);
}*/