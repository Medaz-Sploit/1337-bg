/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:47:07 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/12 18:59:18 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strlen.c"
#include "ft_memcpy.c"

char	*strdup(const char *s1, size_t n)
{
	const char *copy;
	copy = malloc(n);
	if (n < ft_strlen(s1))
		return (0);
	ft_memcpy(copy, s1, n);
}
