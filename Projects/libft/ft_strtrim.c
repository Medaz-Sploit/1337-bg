/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:26:39 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/16 23:53:09 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_start(char **ptr, char **end, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == **ptr)
		{
			(*ptr)++;
			i = 0;
		}
		i++;
	}
	i = 0;
	while (set[i])
	{
		if (set[i] == **end)
		{
			(*end)--;
			i = 0;
		}
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t b;
	char *s;
	char *end;
	char *ptr;

	ptr = (char*)s1;
	end = ft_strlen(s1) + (char*)s1 - 1;
	b = 0;
	find_start(&ptr, &end, set);
	if(!(s = (char*)malloc(end - ptr + 1)))
		return (NULL);
	ft_strlcpy(s, ptr, ft_strlen(ptr) - ft_strlen(end));
	return (s);
}
