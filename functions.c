/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:27:54 by truello           #+#    #+#             */
/*   Updated: 2023/11/13 14:21:18 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		return ;
	push(a, pop(b));
}

void	rotate_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	first = pop(a);
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
}
