/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:15:49 by truello           #+#    #+#             */
/*   Updated: 2023/11/13 15:51:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/ft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* Stack functions */

t_stack	*newstack(int value);
t_stack	*second_elem(t_stack *stack);
t_stack	*last_elem(t_stack *stack);
t_stack	*pop(t_stack **stack);
t_stack	*push(t_stack **stack, t_stack *elem);

/* Operations */

void	swap_a(t_stack *stack);
void	push_a(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);

/* Util functions */

t_bool	ft_isint(long n);

#endif
