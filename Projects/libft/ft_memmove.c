/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:57:12 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/10 23:27:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_memcpy.c"

void	*ft_memmove(void *dst, void *src, int n)
{
	if (*((unsigned char*)src) < *((unsigned char*)dst))
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