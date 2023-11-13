/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:19:30 by truello           #+#    #+#             */
/*   Updated: 2023/11/13 15:32:31 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(int value)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

t_stack	*second_elem(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->next);
}

t_stack	*last_elem(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*res;

	res = *stack;
	*stack = (*stack)->next;
	res->next = 0;
	return (res);
}

t_stack	*push(t_stack **stack, t_stack *elem)
{
	elem->next = *stack;
	*stack = elem;
	return (*stack);
}
