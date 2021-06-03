/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:46:04 by mazoukni          #+#    #+#             */
/*   Updated: 2021/06/03 02:14:57 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This is a function that print the list.
*/

void print_list(t_node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/*
**	This is Fucntion that calculate the length of a List.
*/

int	list_len(t_node *node)
{
	int i;
	
	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i++; 
	}
	return (i);
}

/*
**	This is a function that push new data to the front side of the list.
*/

void pa(t_node **node, int data)
{
	t_node *new_head;
	new_head = (t_node *)malloc(sizeof(t_node));
	
	new_head->data = data;
	new_head->next = (*node);
	new_head->prev = NULL;
	if ((*node) != NULL)
		(*node)->prev = new_head;
	(*node) = new_head;
}


int main(int argc, char **argv)
{
	/*
	**	Initialize the nodes of the double linked list  with NULL
	*/
	int d;
	
	d = 1;
	t_node *a = NULL;
	t_node *b = NULL;
	
	a = (t_node *)malloc(sizeof(t_node));
	b = (t_node *)malloc(sizeof(t_node));
	
	a->data = 0;
	a->prev = NULL;
	a->next = NULL;
	
	b->data = 0;
	b->prev = NULL;
	b->next = NULL;
	while (argc > d)
	{
		pa(&a, atoi(argv[d]));
		d++;
	}
	printf("a|\t");
	print_list(a);
	printf("\nb|\t");
	print_list(b);
	// /*
	// **	fill them with shit uknow
	// */
	// head->data = "Hello World!";
	// head->prev = NULL;
	// head->next = second;

	// second->data = ", Life is full of challenge Keep up your head up.";
	// second->prev = head;
	// second->next = third;

	// third->data = " However just fail often and put emotions aside";
	// third->prev = second;
	// third->next = NULL;
	// pa(&head, "     .....JKIUGS");
	// print_list(head);
	return (0);
}
