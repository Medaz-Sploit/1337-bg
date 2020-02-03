/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:46:32 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/02 04:35:53 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsstr(char *str, int prec)
{
	while (*str && prec)
		ft_putchar(*(str++) + 0 * prec--)
		;
}

void	print_string(va_list argp, t_flags wpz, int *a)
{
    char *str;
    int length;
	char nl[] = "(null)";
	
	str = va_arg(argp, char*);
	str = str ? str : nl;
    length = wpz.prec.state && wpz.prec.value > -1 && wpz.prec.state < ft_strlen(str) ? wpz.prec.value : ft_strlen(str);
    if (wpz.width.state && wpz.width.value > 0)
	{
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (wpz.width.value > length)
			ft_putchar(' ' + 0 * wpz.width.value-- + 0 * (*a)++);
	}
    length = wpz.prec.state && wpz.prec.value > -1 && wpz.prec.state < ft_strlen(str) ? wpz.prec.value : ft_strlen(str);
	ft_putsstr(str, wpz.prec.state ? wpz.prec.value : -1);
	*a += length;
	if (wpz.width.state && wpz.width.value < 0)
	{
    	length = wpz.prec.state && wpz.prec.value > -1 && wpz.prec.state < ft_strlen(str) ? wpz.prec.value : ft_strlen(str);
		if (wpz.zero.state && wpz.zero.value > length)
			length = wpz.zero.value;
		while (-wpz.width.value > length)
			ft_putchar(' ' + 0 * (*a)++ + 0 * wpz.width.value++);
	}
}