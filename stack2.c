/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:28 by truello           #+#    #+#             */
/*   Updated: 2023/11/15 15:44:00 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	if (first == NULL || first->next == NULL)
		return (*stack);
	*stack = first->next;
	first->next = NULL;
	last_elem(*stack)->next = first;
	return (*stack);
}

t_stack	*reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	last = last_elem(*stack);
	if (*stack == NULL || (*stack)->next == NULL || last == NULL)
		return (*stack);
	prev = prev_elem(*stack, last);
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (*stack);
}

t_stack	*prev_elem(t_stack *stack, t_stack *elem)
{
	while (stack)
	{
		if (stack->next == elem)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
