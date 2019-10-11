/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:57:12 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/11 15:31:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_memcpy.c"

void	*ft_memmove(void *dst, void *src, int n)
{
	if (*((unsigned char*)src) < *((unsigned char*)dst) && *((unsigned char*)dst) < *((unsigned char*)src) +n)
	{
		while (n > 0)
		{
			*((char*)dst + (n - 1)) = *((char*)src + (n - 1));
			n--;	
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
