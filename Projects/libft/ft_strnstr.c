/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:34:04 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/13 01:19:05 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strnstr(const char *str, const char *to_find, size_t len)
{


	if (*to_find == '\0')
		return (str);
	while (*str != '\0' && len > 0)
	{

		while (*str == *to_find && len > 0)
		{
			to_find++;
			if (*to_find == '\0')
			{
				return (str);
			}
			str++;
			len--;

		}
		str++;
		len--;
	}
	return (0);
}
