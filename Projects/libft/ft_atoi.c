/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:52:50 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/11 23:28:28 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	if (str[i] <= 32)
		i++;
	if (str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] <= 32)
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + *(str + i) - '0';
		else
			break;
		i++;
	}
	return (res*sign);
}
