/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:43:18 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/11 23:49:23 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int i;
	int j;
	unsigned char str;

	str = (unsigned char) c;
	while (str[i] != '\0')
		i++;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	if (i != j)
		return (0);
	return (1);
}
