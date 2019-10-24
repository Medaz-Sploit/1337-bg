/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:32:37 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/24 02:46:15 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew_bonus(void *content)
{
	 t_list *tmp;
	 
	 tmp = (t_list*)malloc(sizeof(t_list));
	 tmp->content = content;
	 tmp->next = NULL;
	 return (tmp);
}
