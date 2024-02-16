/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort35_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:51:44 by tlai              #+#    #+#             */
/*   Updated: 2024/01/25 13:59:56 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function sorts when stack 'a' has three nodes
// if biggest node == 1. node
	// ra
// if biggest node == 2. node
	// rra
// if first node >  second node
	// swap the first and second node
*/

void	sort_3(t_stack_node **a)
{
	t_stack_node	*current;
	t_stack_node	*biggest_node;

	current = *a;
	biggest_node = current;
	while (current)
	{
		if (current->nbr > biggest_node->nbr)
			biggest_node = current;
		current = current->next;
	}
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

// Helper function to find the node with the smallest number
static t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;
	t_stack_node	*current;

	min_node = stack;
	current = stack;
	while (current)
	{
		if (current->nbr < min_node->nbr)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

/* Pseudo code:
1. RA until find smallest number in stack a
2. PB
3. RA until find smallest number in stack a
4. PB
5. Sort_3(a)
6. if ((*b)->nbr < (*b)->next->nbr)
		sb(b);
7. PA
8. PA
*/

void	sort_5(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;

	while (stack_len(*a) > 3)
	{
		min_node = find_min(*a);
		while ((*a)->nbr != min_node->nbr)
			min_up(a, 0, 0);
		pb(b, a);
	}
	sort_3(a);
	if ((*b)->nbr < (*b)->next->nbr)
		sb(b);
	pa(a, b);
	pa(a, b);
}

// Function returns the length of the stack

int	stack_len(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// Funciton checks if stack is sorted in ascending order
// If the current node is greater than the next node, the stack is not sorted

bool	stack_ordered(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
