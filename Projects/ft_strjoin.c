/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:43:06 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/14 16:44:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	str = ft_strlcat((char*)s1, s2, (sizeof((char*)s1) + sizeof((char*)s2)));
	return ((char*)str);
}
