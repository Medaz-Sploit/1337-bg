/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:52:44 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/01 23:30:00 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag fetch_width(char *format, va_list argp) // %-*d, 3, 1 //
{
    t_flag width;
    
    if (*format == '-')
    {
        format++;
        width.state = 1;
        if (*format == '*')
        {   
            width.value = va_arg(argp, int);
            if (width.value > 0)
                width.value *= -1;
        }
        else
            width.value = ft_atoi((char*)format) * -1;
    }
    else if (ft_isdigit(*format))
    {
        width.state = 1;
        width.value = ft_atoi((char*)format);
    }
    else if (*format == '*')
    {
        width.state = 1;
        width.value = va_arg(argp, int);
    }
    else
        width.state = 0;
    return (width);
}

t_flag fetch_prec(char *format, va_list argp)
{
    t_flag prec;
    
    while (*format != '.' && !ft_isalpha(*format))
        format++;
    if (*format == '.')
    {
        prec.state = 1;
        format++;
        if (*format == '*')
            prec.value = va_arg(argp, int);
        else
            prec.value = ft_atoi((char*)format);
    }
    else
        prec.state = 0;
    return (prec);
}

t_flag fetch_zero(char *format, va_list argp)
{
    t_flag zero;
    
    if (*format == '0')
    {
        zero.state = 1;
        format++;
        if (*format == '*')
            zero.value = va_arg(argp, int);
        else
            zero.value = ft_atoi((char*)format); 
    }
    else
        zero.state = 0;
    return (zero);
}