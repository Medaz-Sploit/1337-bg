/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:07:46 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/25 21:11:00 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cheeeck(int len, t_flags wpz, int integer)
{
	int		ret;

	ret = len;
	if (!I && wpz.prec.state)
		ret -= 1;
	if (!I && WS && WV < 0 && PS && PV < 0)
		ret += 1;
	if (!I && WS && WV > 0 && PS && PV < 0)
		ret += 1;
	return (ret);
}
