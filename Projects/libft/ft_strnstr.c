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
	char	*s;
	char	*find;

	s = (char*)str;
	find = (char*)to_find;
	if (*find == '\0')
		return (s);
	while (*s && len > 0)
	{
		i = 0;
		while ((*(s + i) == *(find + i) || !*(find + i)) && len > 0)
		{
			if (*(find + i) == '\0')
			{
				return (s);
			}
			i++;
			len--;
		}
		s++;
		len--;
	}
	return (0);
}
