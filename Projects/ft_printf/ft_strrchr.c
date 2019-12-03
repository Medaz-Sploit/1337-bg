/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:02:43 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/03 17:49:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (*s != '\0')
	{
		s++;
		len++;
	}
	s--;
	while (i < len)
	{
		if (*s == (char)c)
			return ((char*)s);
		s--;
		i++;
	}
	return (NULL);
}
