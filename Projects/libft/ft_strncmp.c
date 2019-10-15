/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:45:10 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 05:32:48 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	i = 0;
	while (ss1[i] && s2[i] && i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if ((ss1[i] || ss2[i]) && i < n)
		return (ss1[i] - ss2[i]);
	return (0);
}
