/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:59:54 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/26 18:22:10 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unicode(char *format, va_list argp, t_flags wpz, int *a)
{
    ft_putstr(ft_itoa(va_arg(argp, unsigned int)));
	format++;
}