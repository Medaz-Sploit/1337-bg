/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 22:08:17 by mazoukni          #+#    #+#             */
/*   Updated: 2019/08/27 17:53:55 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar();

void	ft_print_ij(char i, char j)
{
	ft_putchar((i / 10) + '0');
	ft_putchar((i % 10) + '0');
	ft_putchar(' ');
	ft_putchar((j / 10) + '0');
	ft_putchar((j % 10) + '0');
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i < j)
			{
				ft_print_ij(i, j);
			}
			if (i != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}
