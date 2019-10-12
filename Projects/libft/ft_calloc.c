/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:00:07 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/12 18:21:08 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bzero.c"
void	*calloc(size_t count, size_t size)
{
	int *ptr;

	ptr = malloc(size * count);
	ft_bzero(ptr, count);
	return (ptr);	
}
