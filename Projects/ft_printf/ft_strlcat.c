/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:02:50 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/03 17:49:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	j = 0;
	len_dst = ft_strlen((const char*)dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dst > size)
		return (len_src + size);
	if (size > len_dst)
	{
		while (src[j] != '\0' && (len_dst + j) < (size - 1))
		{
			dst[len_dst + j] = src[j];
			j++;
		}
		dst[len_dst + j] = '\0';
	}
	return (len_src + len_dst);
}
