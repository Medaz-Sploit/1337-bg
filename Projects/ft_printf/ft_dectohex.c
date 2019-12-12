/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:12:26 by mazoukni          #+#    #+#             */
/*   Updated: 2019/12/12 04:10:13 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Step1: Divide the decimal number by 16 and store the remainder in a variable.  
 **  Step2: If remainder is less than 10, insert ( 48 + remainder ) in a character array.
 **  Step3: If remainder is greater than or equal to 10 then insert ( 55 + remainder ) in a character array.
 **  Step4: Divide the number by 16 now.
 **  Step5: Repeat the above two steps until the number is not equal to 0.
 **  Step6: After this just print the array in reverse order.
 */
#include "ft_printf.h"

int ft_dectohex(int decimal)
{
	int remainder;
	int i;
	char *hex;

	i = 0;
	hex = malloc(17 * sizeof(char));
	remainder = 0;
	while (decimal != 0)
	{
		remainder = decimal % 16;
		if (remainder < 10)
		{
			hex[i++] = remainder + 48;
		}
		else
		{
			hex[i++] = remainder + 55;
		}
		decimal = decimal / 16;
	}
	hex[i] = '\0';
	while (i >= 0)
	{
		ft_putchar(hex[i]);
		i--;
	}
	ft_putchar('\n');
	free(hex);
	return (remainder);
}