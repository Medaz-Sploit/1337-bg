/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:46:04 by mazoukni          #+#    #+#             */
/*   Updated: 2021/05/27 17:49:45 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_node *node)
{
    while (node != NULL)
    {
        printf("%s ", node->data);
        node = node->next;
    }   
}

int main()
{
    t_node *head = NULL;
    t_node *second = NULL;
    t_node *third = NULL;

    head = (t_node *)malloc(sizeof(t_node));
    second = (t_node *)malloc(sizeof(t_node));
    third = (t_node *)malloc(sizeof(t_node));
    
    head->data = "Hello World!";
    head->prev = NULL;
    head->next = second;

    second->data = ", Life is full of challenge Keep up your head up.";
    second->prev = head;
    second->next = third;

    third->data = " However just fail often and put emotions aside";
    third->prev = second;
    third->next = NULL;
    
    print_list(head);
    return (0);
}