/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:40:23 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/26 20:38:28 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int choose_flag(char const format, va_list argp)
{
    if (format == 'd' || format == 'i')
    {
        print_decint(format, argp);
    }
    if (format == 'X' || format == 'x')
    {
        print_hex(format, argp);
    }
    if (format == 'p')
    {
        print_pointer(format, argp);
    }
    if (format == 'u')
    {
        print_unicode(format, argp);
    }
    if (format == 'c')
    {
        print_char(format, argp);
    }
    if (format == 's')
    {
        print_string(format, argp);
    }
}