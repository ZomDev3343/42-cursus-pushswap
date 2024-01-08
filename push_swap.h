/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:15 by truello           #+#    #+#             */
/*   Updated: 2024/01/08 15:55:09 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft.h"

# define SORT_ASCEND 0
# define SORT_DESCEND 1

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* Check Params */

int		is_int(char *str);
int		push_int(char *str, t_stack **stack);

/* Sort Utils */

int		is_sorted(t_stack *stack, int order, size_t len);
int		get_median(t_stack *stack, int len, int *buffer);

/* Stack */

t_stack	*newstack(int value);
t_stack	*pop(t_stack **stack);
void	push(t_stack **stack, t_stack *elem);
t_stack	*last_elem(t_stack **stack);
void	push_back(t_stack **stack, t_stack *elem);

/* Stack 2 */

size_t	stack_len(t_stack *stack);

/* Rotate */

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* Swap */

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* Reverse Rotate */

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Push */

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* Sort */
void	quicksort_a(t_stack **a, t_stack **b, size_t len, size_t under);
void	quicksort_b(t_stack **a, t_stack **b, size_t len, size_t under);

void	fast_sort_3(t_stack **stack);
void	smart_sort_3a(t_stack **a, t_stack **b);
void	smart_sort_3b(t_stack **a, t_stack **b);

/* Utils */
void	print_stack(t_stack *stack, const char *stack_name);
void	print_int_array(int *array, int len);
void	free_stack(t_stack *stack);
int		contains(t_stack *stack, int value);

#endif
