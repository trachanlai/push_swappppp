/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:36 by tlai              #+#    #+#             */
/*   Updated: 2024/01/24 12:35:42 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function moves the required node to the top of the stack, ready to be pushed
Depending on the top_node's position in regard to the median
	rotate or reverse rotate accordingly
*/

void	push_ready(t_stack_node **stack,
		t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static long	ft_atol(const char *str)
{
	size_t	i;
	int		pos_sign;
	long	output;

	i = 0;
	pos_sign = 1;
	output = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos_sign = -1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	return (output * pos_sign);
}
/*
Function to find the last node of the stack to append to the linked list
// If the stack is empty, create a new node and set it as the head of the stack
// If the stack is not empty, find the last node and append the new node
// Set the new node's prev attribute to the last node
// Set the new node's next attribute to NULL
*/

static void	add_node(t_stack_node **stack, long n)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = n;
	new_node->next = NULL;
	if (*stack)
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	else
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
}

// Function to initialize stack a, append the node to the stack
// and handle errors

void	stack_a_errors(t_stack_node **a, char **argv)
{
	int		i;
	long	n;

	i = 1;
	n = 0;
	while (argv[i] != NULL)
	{
		n = ft_atol(argv[i]);
		handle_errors(a, argv[i], n);
		add_node(a, n);
		i++;
	}
}
