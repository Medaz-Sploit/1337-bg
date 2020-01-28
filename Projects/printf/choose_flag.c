/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:40:23 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/27 17:20:14 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag ft_asso(t_flag flag, int b)
{
    flag.value = b;
    flag.state = 1;
    return (flag);
}

t_flags ft_reshape(t_flags wpz)
{
    t_flags shape;
    
    shape.width.state = 0;
    shape.zero.state = 0;
    shape.prec.state = 0;
    if (wpz.prec.state)
    {
        shape.prec = ft_asso(shape.prec, wpz.prec.value);
        shape.zero = ft_asso(shape.zero, wpz.prec.value);
        if (wpz.zero.state)
            shape.width = ft_asso(shape.width, wpz.zero.value);
        else if (wpz.width.state)
            shape.width = ft_asso(shape.width, wpz.width.value);
    }
    else if (wpz.zero.state)
        shape.zero = ft_asso(shape.zero, wpz.zero.value);
    else if (wpz.width.state)
        shape.width = ft_asso(shape.width, wpz.width.value);
    
    return (shape);
}

char const *choose_flag(char *format, va_list argp , int *a) // %0987.12d
{
    t_flags wpz;
    
    wpz.width = fetch_width(format, argp);
    wpz.zero = fetch_zero(format, argp);
    wpz.prec = fetch_prec(format, argp);
    
    while (!ft_isalpha(*format))
        format++;
    if (*format == 'd' || *format == 'i' || *format == 'c')
        print_decint((char*)format, argp, ft_reshape(wpz), a);
        
    /*else if (*format == 'X' || *format == 'x' || *format == 'u')
        print_hex(format, argp, ft_reshape(wpz), a);
    else if (*format == 'p')
        print_pointer(format, argp, wpz, a);
    else if (*format == 's')
        print_string(format, argp, wpz, a);*/
    format++;
    return (format);  
}