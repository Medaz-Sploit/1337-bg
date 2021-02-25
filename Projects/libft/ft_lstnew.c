/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:00:34 by mazoukni          #+#    #+#             */
/*   Updated: 2021/01/04 18:22:32 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
  int data;
  struct s_list* next;
} t_list;

t_list
  *ft_lstnew(void *content)
{
  t_list *elt;
  if(!(elt = (t_list*)malloc(sizeof(*elt))))
    return (NULL);
  elt->data = content;
  elt->next = NULL;
  return (elt);
}


// 123
// 456
// 789

// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}

// arr[(2 * 3) + 1]

// node *ft_lstm\neww
