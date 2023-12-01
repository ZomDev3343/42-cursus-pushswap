/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:17:44 by truello           #+#    #+#             */
/*   Updated: 2023/12/01 16:25:29 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3a(t_stack **a, int len)
{
	if (len == 2)
	{
		if (!is_sorted(*a, SORT_ASCEND, len))
			sa(a);
	}
	else if (len == 3 && stack_len(*a) == 3)
		fast_sort_3(a);
	else if (len == 3)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		if ((*a)->value > (*a)->next->next->value)
		{
			ra(a);
			sa(a);
			rra(a);
			sa(a);
		}
		if ((*a)->next->value > (*a)->next->next->value)
		{
			ra(a);
			sa(a);
			rra(a);
		}
	}
}

static void	sort_3b(t_stack **a, t_stack **b, int len)
{
	if (len <= 2)
	{
		if (!is_sorted(*b, SORT_DESCEND, len))
			sb(b);
		return (pa(a, b), pa(a, b));
	}
	else if (len == 3)
		smart_sort_3b(a, b);
}

static void	push_all_b(t_stack **a, t_stack **b, size_t len)
{
	while (len--)
		pa(a, b);
}

void	quicksort_a(t_stack **a, t_stack **b, size_t len, size_t under)
{
	int		median;
	size_t	i;

	if (len <= 3)
		sort_3a(a, len);
	else
	{
		if (is_sorted(*a, SORT_ASCEND, len)
			|| get_median(*a, len, &median) == 0)
			return ;
		i = len;
		while (i != len / 2 + len % 2)
		{
			if ((*a)->value < median && (i--))
				pb(a, b);
			else if (++under)
				ra(a);
		}
		while (len / 2 + len % 2 != stack_len(*a) && under--)
			rra(a);
		quicksort_a(a, b, len / 2 + len % 2, 0);
		quicksort_b(a, b, len / 2, 0);
	}
}

void	quicksort_b(t_stack **a, t_stack **b, size_t len, size_t under)
{
	int		median;
	size_t	i;

	if (len <= 3)
		sort_3b(a, b, len);
	else
	{
		if (is_sorted(*b, SORT_DESCEND, len))
			return (push_all_b(a, b, len));
		if (get_median(*b, len, &median) == 0)
			return ;
		i = len;
		while (i != len / 2)
		{
			if ((*b)->value >= median && (i--))
				pa(a, b);
			else if (++under)
				rb(b);
		}
		while (len / 2 != stack_len(*b) && under--)
			rrb(b);
		quicksort_a(a, b, len / 2 + len % 2, 0);
		quicksort_b(a, b, len / 2, 0);
	}
}
