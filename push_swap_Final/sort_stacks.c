/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:44:15 by tlai              #+#    #+#             */
/*   Updated: 2024/01/25 14:00:06 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function moves the smallest number to the top
// Rotate or reverse rotate depending on the position of the node on the median

void	min_up(t_stack_node **a, int min_index, int length)
{
	t_stack_node	*current;
	t_stack_node	*min;

	current = *a;
	min = current;
	while (current)
	{
		if (current->nbr < min->nbr)
		{
			min = current;
			min_index = length;
		}
		current = current->next;
		length++;
	}
	while ((*a)->nbr != min->nbr)
	{
		if (min_index < length / 2)
			ra(a);
		else
			rra(a);
	}
}

/*
Function prepares the cheapest node on top of the stack to be pushed from 'a2b',
	until there are 3 nodes left in 'a'
 // Check if both the cheapest 'a' node and its target 'b' node are:
// above the median: ra, rb
// Below median, rra, rrb

// Ensure the cheapest 'a' node to be pushed to 'b' is at the top
// Ensure the target 'b' node is at the top
// Push the cheapest 'a' node to 'b'
*/

static void	rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node, bool reverse)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		if (reverse)
			rrr(a, b);
		else
			rr(a, b);
	}
	present_index(*a);
	present_index(*b);
}

static void	move_a2b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*current_node;

	cheapest_node = NULL;
	if (!*a)
		return ;
	current_node = *a;
	while (current_node)
	{
		if (current_node->cheapest)
			cheapest_node = current_node;
		current_node = current_node->next;
	}
	if (cheapest_node == NULL)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate(a, b, cheapest_node, false);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rotate(a, b, cheapest_node, true);
	push_ready(a, cheapest_node, 'a');
	push_ready(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

// Function prepares the cheapest node on top of the stack to push 'b2a'

static void	move_b2a(t_stack_node **a, t_stack_node **b)
{
	push_ready(a, (*b)->target_node, 'a');
	pa(a, b);
}

/*
Function sorts stacks 'a' if it has more than 3 unordered nodes
// Initialize the nodes of stack 'a' and 'b'
// Move all 'a' nodes to 'b' until there are 3 nodes left in 'a'
// Sort the 3 nodes left in 'a'
// Move all 'b' nodes back to the sorted 'a' stack
// Update the index of stack 'a'
// Ensure the smallest number is on top
*/

void	turk_alg(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int	len_b;
	int	min_index;
	int	length;

	min_index = 0;
	length = 0;
	len_a = stack_len(*a);
	len_b = stack_len(*b);
	if (len_b <= 2 && !stack_ordered(*a))
		pb(b, a);
	while (len_a > 3 && !stack_ordered(*a))
	{
		init_nodes_a(*a, *b);
		move_a2b(a, b);
	}
	if (len_a <= 3)
		sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b2a(a, b);
	}
	present_index(*a);
	min_up(a, min_index, length);
}
