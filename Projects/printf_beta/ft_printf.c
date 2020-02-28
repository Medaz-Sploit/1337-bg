/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:26:19 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/28 00:57:56 by mazoukni         ###   ########.fr       */
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
int main()
{

	ft_printf("%3.2x %d %s %c %u %i %p %--%\n",231,0,NULL,9,-200,0,(void *)0); 
	printf("%3.2x %d %s %c %u %i %p %--%\n",231,0,NULL,9,-200,0,(void *)0); 
	return (0);
}
