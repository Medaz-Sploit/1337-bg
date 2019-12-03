/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:34:04 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/03 17:49:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	char	*s;
	char	*find;

	s = (char*)str;
	find = (char*)to_find;
	if (*find == '\0')
		return (s);
	while (*s && len > 0)
	{
		i = 0;
		while (*(s + i) == *(find + i) && i < len && s[i] != '\0')
		{
			i++;
		}
		if (find[i] == '\0')
			return (s);
		s++;
		len--;
	}
	return (0);
}
