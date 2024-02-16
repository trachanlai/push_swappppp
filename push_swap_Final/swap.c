/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:38:45 by tlai              #+#    #+#             */
/*   Updated: 2024/01/19 12:32:06 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function swaps the top two nodes of a stack

// Set the first node as the head of the stack
// Set the second node as the head of the stack
// Set the first node's next attribute to the second node's next attribute
// Set the second node's prev attribute to NULL, properly terminating the stack
// Set the second node's next attribute to the first node
// Set the first node's prev attribute to the second node
// if there is a next node
	// Set the "second node"'s prev attribute to the first node
	// Set the second node as the top node
*/

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
