/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:13:22 by truello           #+#    #+#             */
/*   Updated: 2023/12/01 16:40:22 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	ft_printf("pa\n");
	push(a, pop(b));
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	ft_printf("pb\n");
	push(b, pop(a));
}
