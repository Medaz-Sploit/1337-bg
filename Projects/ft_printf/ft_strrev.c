/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:13:04 by mazoukni          #+#    #+#             */
/*   Updated: 2019/08/31 13:34:12 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strrev(char *str)
{
	int r;
	int l;

	l = 0;
	r = ft_strlen(str) - 1;
	while (l < r)
	{
		ft_swap((str + l), (str + r));
		l++;
		r--;
	}
	return (str);
}
