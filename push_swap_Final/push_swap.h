/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:22:34 by tlai              #+#    #+#             */
/*   Updated: 2024/01/25 13:58:20 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>  // For INT_MAX and INT_MIN
# include <stdarg.h>  // For va_list, va_start, va_arg, va_end
# include <stdbool.h> // For bool, true and false
# include <stdlib.h>  // For malloc, free, exit
# include <unistd.h>  // For write

// Struct: Contatainer of data types used in the program
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					nbr_moves;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Stack initiation, calling error functions 
void					stack_a_errors(t_stack_node **stack_a, char **argv);
void					handle_errors(t_stack_node **a, char *arg, long n);
void					free_stack(t_stack_node **stack);
int						ft_printf(const char *str, ...);
char					**ft_split(char *str, char separator);

// Nodes initiation
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					present_index(t_stack_node *stack);
void					push_ready(t_stack_node **s, t_stack_node *n, char c);

// Operations
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

// Stack utils
int						stack_len(t_stack_node *stack);
bool					stack_ordered(t_stack_node *stack);
void					min_up(t_stack_node **a, int min_index, int length);

// Sorting algorithms
void					turk_alg(t_stack_node **a, t_stack_node **b);
void					sort_3(t_stack_node **a);
void					sort_5(t_stack_node **a, t_stack_node **b);

#endif
