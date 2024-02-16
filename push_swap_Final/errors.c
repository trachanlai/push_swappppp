/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:02:19 by tlai              #+#    #+#             */
/*   Updated: 2024/01/24 12:13:51 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Error function returning 1 if there is an error.
All called in 'int init_stack_a' / handle_errors.c
*/

static int	er_nondigit(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' || *str > '9')
		return (1);
	while (*++str)
	{
		if (*str < '0' || *str > '9')
			return (1);
	}
	return (0);
}

static int	er_dup(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*next_node;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		next_node = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = next_node;
	}
}

// function frees stack and prints error message when encountering unique error

static void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

void	handle_errors(t_stack_node **a, char *arg, long n)
{
	if (er_nondigit(arg))
		free_errors(a);
	if (n > INT_MAX || n < INT_MIN)
		free_errors(a);
	if (er_dup(*a, n))
		free_errors(a);
}
