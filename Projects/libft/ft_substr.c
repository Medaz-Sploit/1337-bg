/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:31:27 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/20 03:58:43 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s)
		return (NULL);
	if (!(sub = malloc((ft_strlen((char*)s) - start)*sizeof(char))))
		return (NULL);
	ft_strlcpy(sub, (char*)(s + start), len);
	return (sub);
}
