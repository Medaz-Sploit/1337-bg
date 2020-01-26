/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:51:46 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/26 18:21:07 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(char *format, va_list argp, t_flags wpz, int *a)
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
}