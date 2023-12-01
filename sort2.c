/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:28:42 by truello           #+#    #+#             */
/*   Updated: 2023/12/01 16:11:09 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * 3 1 2 4
 * 2 3 1 4
 * 2 1 3 4
 * 1 3 2 4
 * 3 2 1 4
 */
void	fast_sort_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		ra(a);
	else if ((*a)->next->next->value < (*a)->value
		&& (*a)->value < (*a)->next->value)
		rra(a);
	else if ((*a)->next->value < (*a)->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
		return (rra(a), sa(a));
	else if (is_sorted(*a, SORT_DESCEND, 3))
		return (sa(a), rra(a));
}

static int	get_max_in_3(t_stack *stack)
{
	int	max;

	max = stack->value;
	if (stack->next->value > max)
		max = stack->next->value;
	if (stack->next->next->value > max)
		max = stack->next->next->value;
	return (max);
}

static int	get_min_in_3(t_stack *stack)
{
	int	min;

	min = stack->value;
	if (stack->next->value < min)
		min = stack->next->value;
	if (stack->next->next->value < min)
		min = stack->next->next->value;
	return (min);
}

void	smart_sort_3b(t_stack **a, t_stack **b)
{
	int	max;
	int	i;

	i = 0;
	max = get_max_in_3(*b);
	while ((*b)->value != max && ++i)
		rb(b);
	pa(a, b);
	while (i--)
		rrb(b);
	if ((*b)->value > (*b)->next->value)
		return (pa(a, b), pa(a, b));
	else
		return (sb(b), pa(a, b), pa(a, b));
}

void	smart_sort_3a(t_stack **a, t_stack **b)
{
	int	min;
	int	i;

	i = 0;
	min = get_min_in_3(*a);
	while ((*a)->value != min && ++i)
		ra(a);
	pb(a, b);
	while (i--)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
	pa(a, b);
}
