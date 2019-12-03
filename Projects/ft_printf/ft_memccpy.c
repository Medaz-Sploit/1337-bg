/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:14:36 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/03 17:49:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)src;
	while (n > 0)
	{
		if ((unsigned char)c == *ptr)
		{
			*((unsigned char*)dst) = *ptr;
			return (dst + 1);
			break ;
		}
		*((unsigned char*)dst) = *ptr;
		n--;
		ptr++;
		dst++;
	}
	return (0);
}
