/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:44:02 by truello           #+#    #+#             */
/*   Updated: 2023/11/14 16:30:50 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Util function to print the content of an integer list */
void	print_int_array(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("Num [%d] : %d\n", i, array[i]);
		i++;
	}
}

/* Util function to print the content of a stack */
void	print_stack(t_stack *stack)
{
	ft_printf("Stack printing : \n");
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
	ft_printf("End of stack printing : \n");
}
