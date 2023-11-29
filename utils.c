/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:30:38 by truello           #+#    #+#             */
/*   Updated: 2023/11/29 16:54:26 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *stack_name)
{
	ft_printf("Print Stack : %s\n", stack_name);
	while (stack)
	{
		ft_printf("Value : %d, Next : %p\n", stack->value, stack->next);
		stack = stack->next;
	}
	ft_printf("End of printing\n");
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	if (stack->next != NULL)
		free_stack(stack->next);
	free(stack);
}

int	contains(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}
