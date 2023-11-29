/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:46:29 by truello           #+#    #+#             */
/*   Updated: 2023/11/28 15:49:32 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*pop(t_stack **stack)
{
	t_stack	*res;

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
