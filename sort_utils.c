/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:17:24 by truello           #+#    #+#             */
/*   Updated: 2023/12/01 16:24:08 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* For order, must be using SORT_ASCEND OR SORT_DESCEND */
int	is_sorted(t_stack *stack, int order, size_t len)
{
	t_stack	*last;

	last = stack;
	stack = stack->next;
	while (len-- && stack)
	{
		if ((stack->value < last->value && order == SORT_ASCEND)
			|| (stack->value > last->value && order == SORT_DESCEND))
			return (FALSE);
		last = stack;
		stack = stack->next;
	}
	return (TRUE);
}

static void	sort_array(int *array, int len)
{
	int	i;
	int	j;

	i = len - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (array[j + 1] < array[j])
				ft_swap_int(array + j + 1, array + j);
			j++;
		}
		i--;
	}
}

int	get_median(t_stack *stack, int len, int *buffer)
{
	int	*array;
	int	i;

	if (!stack)
		return (0);
	array = (int *) malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		array[i] = stack->value;
		stack = stack->next;
	}
	sort_array(array, len);
	return (*buffer = array[len / 2], free(array), 1);
}
