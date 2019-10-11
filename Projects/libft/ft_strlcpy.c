/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:36:37 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/11 15:56:33 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcpy(char *dst, char *src, unsigned int n)
{
	int len;

	len = 0;
	while (src[len])
		len++;
	while (*src  != '\0' && n > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return (len);
}
