/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:55:47 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/26 20:43:53 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_decint(char const format, va_list argp)
{
    ft_putstr(ft_itoa(va_arg(argp, int)));
	format++;
    return (1);
}