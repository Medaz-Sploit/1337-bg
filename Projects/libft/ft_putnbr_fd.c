/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:31:35 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/17 22:55:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb, int fd)
{
	if (nb >= 0 && nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
		ft_putnbr(nb / 10);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}
