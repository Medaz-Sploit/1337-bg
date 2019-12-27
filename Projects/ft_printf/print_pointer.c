/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:57:49 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/26 20:44:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(char const format, va_list argp)
{
    size_t d;
    
    ft_putstr("0x");
	d = va_arg(argp, size_t);
	ft_dectohex(*format , d);
	format++;
    return (1);
}