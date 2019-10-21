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

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{

	const size_t srclen  = ft_strlen(src);
	const size_t dstlen  = ft_strnlen(dst, size);

	if (dstlen == size)
		return (size + srclen);
	if (srclen < (size - dstlen))
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - 1);
		dst[dstlen + size - 1] = '\0';
	}
	return (dstlen + srclen);
}
