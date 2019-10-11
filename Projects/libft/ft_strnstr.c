/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:34:04 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/11 22:42:04 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(comst char *str, const char *to_find, size_t len)
{
	int i;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0' && len > 0)
	{
		i = 0;
		while (*(str + i) == *(to_find + i))
		{
			i++;
			if (*(to_find + i) == '\0')
				return (str);
		}
		str++;
		len--;
	}
	return (str);
}
