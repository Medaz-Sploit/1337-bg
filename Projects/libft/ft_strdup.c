/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:47:07 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/12 18:59:18 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_strlen.c"
#include "ft_strlcpy.c"

char	*strdup(const char *s1)
{
	const char *copy;
	copy = malloc((ft_strlen(s1) - 1)*sizeof(char));
	ft_strlcpy((char)copy,(char)s1, sizeof(s1));
}
