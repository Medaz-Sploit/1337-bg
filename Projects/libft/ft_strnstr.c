/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:34:04 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 05:20:55 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;

	if (*to_find == '\0')
		return ((char*)str);
	while (*str != '\0' && len > 0)
	{
		i = 0;
		while ((*(str + i) == *(to_find + i) || !*(to_find + i)) && len > 0)
		{
			if (*(to_find + i) == '\0')
			{
				return ((char*)str);
			}
			i++;
			len--;
		}
		str++;
		len--;
	}
	return (0);
}
