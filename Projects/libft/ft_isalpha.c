/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:35:32 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/11 23:42:34 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isapha(int c)
{
	int i;
	int j;
	unsigned char str;
	str = (unsigned char) c;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		i++;
	if (i != j)
		return (0);
	return (1);
}
