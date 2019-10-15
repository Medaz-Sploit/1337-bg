/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:26:39 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/14 16:40:36 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const *str;
	str = (char const*) malloc(ft_strlen((char*)s1)*sizeof(char));
   	if (*set == '\0')
		return ((char*)s1);	
	return (0);
}
