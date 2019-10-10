/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:14:36 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/10 16:58:59 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst,void *src, int c, int n)
{
	while (n > 0)
	{
		*((char*)dst) = *((char*)src);
		if((unsigned char) c == *((char*)src))
		{
			return (dst);
			break;
		}
		n--;
		dst++;
		src++;
	}
	return (0);
}
