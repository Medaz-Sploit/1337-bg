/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:46:32 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/26 18:21:49 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *format, va_list argp, t_flags wpz, int *a)
{
    size_t d;
    
    ft_putstr("0x");
	d = va_arg(argp, size_t);
	ft_dectohex(*format , d);
	format++;
}