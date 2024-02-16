/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:05 by tlai              #+#    #+#             */
/*   Updated: 2024/01/26 12:20:17 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
How to run Visualizer:
- make
- cd to "push_swap_visualizer"
- cd to "build"
- run "./bin/visualizer"

- Controls panel: Adjust font size
- Values panel: Input values  --> Shuffle --> Compute
- Controls panel: Start and adjust speed

Checker Mac command:
- make
- ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
*/

// Leak Check:
// void leaks()
// {
// 	system("leaks push_swap");
// }
// inside main: leaks();

/*
Program takes random input of numbers and sorts them in ascending order
using Turk algorithm.
*/

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_a_errors(&a, argv);
	while (!stack_ordered(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_3(&a);
		else if (stack_len(a) == 5)
			sort_5(&a, &b);
		else
			turk_alg(&a, &b);
	}
	free_stack(&a);
	return (0);
}
