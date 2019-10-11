/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:36:37 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/11 19:13:39 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int	ft_strlcpy(char *dst, char *src, unsigned int n)
{
	int len;
	len = 0;

	while (*src  != '\0' && n - 1 > 0)
	{
		*dst = *src;
		dst++;
		len++;
		src++;
		n--;
	}
	*dst = '\0';
	return (len + ft_strlen(src));
}
