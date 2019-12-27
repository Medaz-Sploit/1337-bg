/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:59:54 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/26 20:43:45 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unicod(char const format, va_list argp)
{
    ft_putstr(ft_itoa(va_arg(argp, unsigned int)));
	format++;
    return (1);
}