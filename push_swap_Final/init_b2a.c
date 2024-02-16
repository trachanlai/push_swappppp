/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b2a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:23:35 by tlai              #+#    #+#             */
/*   Updated: 2024/01/23 12:15:31 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function to find 'b' node's target: 'closest bigger number' in stack 'a'
IF NOT, set the target node to the smallest node in stack 'a'
*/

t_stack_node	*find_target_node_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	int				best_match_index;

	current_a = a;
	target_node = NULL;
	best_match_index = INT_MAX;
	while (current_a)
	{
		if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
		{
			best_match_index = current_a->nbr;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	return (target_node);
}

void	target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	int				min;
	t_stack_node	*current_node;

	while (b)
	{
		target_node = find_target_node_b(a, b);
		if (!target_node)
		{
			min = INT_MAX;
			current_node = a;
			while (current_node)
			{
				if (current_node->nbr < min)
				{
					min = current_node->nbr;
					target_node = current_node;
				}
				current_node = current_node->next;
			}
		}
		b->target_node = target_node;
		b = b->next;
	}
}

// function is setting up some initial state on the nodes in stacks a and b
void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	present_index(a);
	present_index(b);
	target_b(a, b);
}
