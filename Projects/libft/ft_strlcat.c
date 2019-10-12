/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:02:50 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/12 17:30:26 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcat(char *dst, const char *src, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && n - ft_strlen(dst) - 1 > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
		n--;
	}
	dst[i] = '\0';
	if (len_dst > n)
		return (len_src + n);
	return (len_src + len_dst);
}
