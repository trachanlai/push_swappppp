/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:06:05 by tlai              #+#    #+#             */
/*   Updated: 2024/01/23 12:20:30 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function sets the index of each node in stack 'a' to its current position
void	present_index(t_stack_node *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i >= median)
			stack->above_median = false;
		else
			stack->above_median = true;
		stack = stack->next;
		++i;
	}
}

/*
Funtion to find 'a' node's target: "closest smaller number" in stack 'b'
Storing the best match index of 'a' in stack 'b'
IF NOT, set the target node to the biggest node in stack 'b'
*/

t_stack_node	*find_target_node_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*present_b;
	t_stack_node	*target_node;
	int				best_match_index;

	present_b = b;
	target_node = NULL;
	best_match_index = INT_MIN;
	while (present_b)
	{
		if (present_b->nbr < a->nbr && present_b->nbr > best_match_index)
		{
			best_match_index = present_b->nbr;
			target_node = present_b;
		}
		present_b = present_b->next;
	}
	return (target_node);
}

void	target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	int				max;
	t_stack_node	*current_node;

	while (a)
	{
		target_node = find_target_node_a(a, b);
		if (!target_node)
		{
			max = INT_MIN;
			current_node = b;
			while (current_node)
			{
				if (current_node->nbr > max)
				{
					max = current_node->nbr;
					target_node = current_node;
				}
				current_node = current_node->next;
			}
		}
		a->target_node = target_node;
		a = a->next;
	}
}

/*
Function to calculate the push cost of each node in stack 'a'
if 'a' node > median: count backward - set push cost to the index of 'a' node
if 'a' node < median: push cost is length of stack 'a' - the index of 'a' node
*/

static int	calculate_moves(t_stack_node *node, t_stack_node *a,
		t_stack_node *b)
{
	int	len_a;
	int	len_b;
	int	nbr_moves;

	len_a = stack_len(a);
	len_b = stack_len(b);
	nbr_moves = node->index;
	if (!node->above_median)
		nbr_moves = len_a - node->index;
	if (node->target_node->above_median)
		nbr_moves += node->target_node->index;
	else
		nbr_moves += len_b - node->target_node->index;
	return (nbr_moves);
}

/*
Function sets the node's "cheapest"attribute to true or false
*/

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*cheapest_node;

	present_index(a);
	present_index(b);
	target_a(a, b);
	current = a;
	while (current)
	{
		current->nbr_moves = calculate_moves(current, a, b);
		current = current->next;
	}
	if (!a)
		return ;
	cheapest_node = a;
	a = a->next;
	while (a)
	{
		if (a->nbr_moves < cheapest_node->nbr_moves)
			cheapest_node = a;
		a = a->next;
	}
	cheapest_node->cheapest = true;
}
