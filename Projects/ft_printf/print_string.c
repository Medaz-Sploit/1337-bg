/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:46:32 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/26 20:43:13 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(char const format, va_list argp)
{
    size_t d;
    
    ft_putstr("0x");
	d = va_arg(argp, size_t);
	ft_dectohex(*format , d);
	format++;
    return (1);
}