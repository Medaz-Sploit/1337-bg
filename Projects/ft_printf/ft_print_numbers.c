/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 22:50:32 by mazoukni          #+#    #+#             */
/*   Updated: 2019/08/25 22:10:09 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar();

void	ft_print_numbers(void)
{
	char	n;

	n = 48;
	while (n <= 57)
	{
		ft_putchar(n);
		n++;
	}
}
