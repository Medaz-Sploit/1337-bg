/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:51:46 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/26 20:43:30 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hex(char const format, va_list argp)
{
    if (format == 'x')
    {
        ft_dectohex(*format, va_arg(argp, unsigned int));            
        format++;
    }
    if (format == 'X')
    {
        ft_dectohex(*format, va_arg(argp, unsigned int));
	    format++;
    }
    return (1);
}