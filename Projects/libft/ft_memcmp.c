/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:19:04 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 01:22:08 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (ss1[i] && ss2[i] && (unsigned long)i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if ((ss1[i] || ss2[i]) && (unsigned long)i < n)
		return (ss1[i] - ss2[i]);
	return (0);
}
