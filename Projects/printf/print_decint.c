/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:55:47 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/22 03:32:48 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_nbrlen(int integer)
{
    int length;

    length = 0;
    while (integer != 0)
    {
        integer = integer / 10;
        length++;
    }
    return length;
}

void print_decint(char const *format, va_list argp, t_flags wpz, int *a)
{
    int integer;
    int length;

    integer = va_arg(argp, int);
    length = *format == 'c' ? 1 : ft_nbrlen(integer);    
}