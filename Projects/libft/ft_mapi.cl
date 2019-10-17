# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_mapi.cl                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 22:31:49 by mazoukni          #+#    #+#              #
#    Updated: 2019/10/17 22:35:56 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

char	*ft_mapi(char *s, char (*f)(unsigned int, char))
{
	size_t i;
	char *str;

	i = 0;
	str = malloc(sizeof(char) * LEN(s));
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
