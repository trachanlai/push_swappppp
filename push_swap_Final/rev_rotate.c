/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:29:19 by tlai              #+#    #+#             */
/*   Updated: 2024/01/19 12:05:41 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function rotates the stack down by one node:
// Check if the last node has a next node
// If it does, set the last node as the head of the stack

// Detach the last node and update the second to last node
// Attach the last node at the beginning of the stack
// Update the second node's prev attribute
*/

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*prev_last;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev_last = NULL;
	last = *stack;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	*stack = last;
	(*stack)->next->prev = *stack;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
