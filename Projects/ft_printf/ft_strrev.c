/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:13:04 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/12 03:33:43 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int r;
	int l;

	l = 0;
	r = ft_strlen(str) - 1;
	while (l < r)
	{
		ft_swap((int*)(str + l), (int*)(str + r));
		l++;
		r--;
	}
	return (str);
}
