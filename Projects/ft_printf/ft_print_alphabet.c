/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:15:36 by mazoukni          #+#    #+#             */
/*   Updated: 2019/08/25 20:11:01 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar();

void	ft_print_alphabet(void)
{
	int	n;

	n = 97;
	while (n <= 122)
	{
		ft_putchar(n);
		n++;
	}
}
