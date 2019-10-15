/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:14:36 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 01:17:25 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, void *src, int c, int n)
{
	while (n > 0)
	{
		if ((unsigned char)c == *((char*)src))
		{
			*((char*)dst) = *((char*)src);
			return (dst + 1);
			break ;
		}
		*((char*)dst) = *((char*)src);
		n--;
		dst++;
		src++;
	}
	return (0);
}
