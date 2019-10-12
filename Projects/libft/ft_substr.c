/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:31:27 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/12 23:32:58 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_strlcpy.c"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	
	sub = malloc((ft_strlen((char*)s) - start)*sizeof(char));
	ft_strlcpy(sub, (char*)(s + start), len);
	return (sub);
}
