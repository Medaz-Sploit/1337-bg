/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:02:50 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 07:08:20 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	j = 0;
	len_dst = ft_strlen((const char*)dst);
	len_src = ft_strlen(src);
	while (src[j] != '\0' && j < n)
	{
		dst[len_dst] = src[j];
		len_dst++;
		j++;
		n--;
	}
	dst[j] = '\0';
	if (len_dst > n)
		return (len_src + n);
	return (len_src + len_dst);
}
