/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:35:20 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 02:42:25 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_tab(char **tab, int b)
{
	while (b <= 0)
	{
		free(tab[b]);
		b++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
char	word(char *str,  char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] == c)
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
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

char	chars(char *str , char c)
{
	int		i;

	i = 1;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

void	insert_element(char *str, char **tab, int i , char c)
{
	int		j;

	j = 0;
	while (str[j] != c && str[j] != '\0')
	{
		tab[i][j] = str[j];
		j++;
	}
	tab[i][j] = '\0';
}

char	**ft_split(char const *str , char c) 
{
	char	**tab;
	char	*ptr;
	int		j;
	int		i;
	int		b;

	j = word((char*)str, c);
	ptr = (char*)str;
	i = 0;
	b = 0;
	if (!str || !(tab = (char **)malloc((word((char*)str, c) + 1) 
		* sizeof(char*))))
		return (NULL);
	while (*ptr != '\0')
	{
		while (*ptr == c)
			ptr++;
		if (*ptr == '\0')
			break ;
		if (!(tab[i] = (char *)malloc(chars(ptr, c) * sizeof(char))))
			if(!(free_tab(tab, b)))
				break;
		insert_element(ptr, tab, i, c);
		ptr += chars(ptr, c);
		i++;
	}
	tab[j] = 0;
	return (tab);
}
