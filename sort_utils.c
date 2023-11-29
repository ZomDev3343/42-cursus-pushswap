/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:17:24 by truello           #+#    #+#             */
/*   Updated: 2023/11/28 13:35:18 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* For order, must be using SORT_ASCEND OR SORT_DESCEND */
int	is_sorted(t_stack *stack, int order)
{
	t_stack	*last;

	last = stack;
	if (!last)
		return (TRUE);
	stack = stack->next;
	while (stack)
	{
		if ((stack->value < last->value && order == SORT_ASCEND)
			|| (stack->value > last->value && order == SORT_DESCEND))
			return (FALSE);
	}
	return (TRUE);
}
