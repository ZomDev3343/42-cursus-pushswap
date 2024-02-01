/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:46:29 by truello           #+#    #+#             */
/*   Updated: 2023/11/30 17:22:20 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(int value)
{
	t_stack	*res;

	res = (t_stack *) malloc(sizeof(t_stack));
	res->value = value;
	res->next = NULL;
	return (res);
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*res;

	if (!stack || !*stack)
		return (NULL);
	res = *stack;
	*stack = (*stack)->next;
	res->next = NULL;
	return (res);
}

void	push(t_stack **stack, t_stack *elem)
{
	if (elem == NULL)
		return ;
	elem->next = *stack;
	*stack = elem;
}

t_stack	*last_elem(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	push_back(t_stack **stack, t_stack *elem)
{
	t_stack	*last;

	if (elem == NULL)
		return ;
	last = last_elem(stack);
	if (last == NULL)
		push(stack, elem);
	else
		last->next = elem;
}
