/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:37:13 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/17 16:53:25 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] == 32 || str[i] == 9 || str[i] == 10)
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == 32 || str[i] == 9 || str[i] == 10)
		{
			if (str[i + 1] == 9 || str[i + 1] == 32 ||
			str[i + 1] == 10 || str[i + 1] == '\0')
			{
				i++;
				continue;
			}
			count++;
		}
		i++;
	}
	return (count);
}

char	chars(char *str)
{
	int		i;

	i = 1;
	while (str[i] != '\0' && str[i] != 32 && str[i] != 9 && str[i] != 10)
	{
		i++;
	}
	return (i);
}

void	insert_element(char *str, char **tab, int i)
{
	int		j;

	j = 0;
	while (str[j] != 32 && str[j] != 9 && str[j] != 10 && str[j] != '\0')
	{
		tab[i][j] = str[j];
		j++;
	}
	tab[i][j] = '\0';
}

char	**ft_split_whitespaces(char const *str , char c) 
{
	char	**tab;
	char	*ptr;
	int		j;
	int		i;

	j = word(str);
	ptr = (char*)str;
	i = 0;
	tab = (char **)malloc((word(str) + 1) * sizeof(char*));
	while (*ptr != '\0')
	{
		while (*ptr == c)
			ptr++;
		if (*ptr == '\0')
			break ;
		tab[i] = (char *)malloc(chars(ptr) * sizeof(char));
		insert_element(ptr, tab, i);
		ptr += chars(ptr);
		i++;
	}
	tab[j] = 0;
	return (tab);
}
