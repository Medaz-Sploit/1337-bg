/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:55:56 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 22:08:46 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*   Check if bla is bla	*/
char	*ft_strchr(const char *s, int c)
{
	if (c == '\0' || !*s)
		return ((char*)(s + ft_strlen(s)));
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	return (0);
}
