/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:15 by truello           #+#    #+#             */
/*   Updated: 2023/11/29 16:51:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft.h"

# define SORT_ASCEND 0
# define SORT_DESCEND 1

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;
/* Check Params */

int		is_int(char *str);
int		push_int(char *str, t_stack **stack);

/* Sort Utils */

int		is_sorted(t_stack *stack, int order);

/* Stack */

t_stack	*newstack(int value);
t_stack	*pop(t_stack **stack);
void	push(t_stack **stack, t_stack *elem);
t_stack	*last_elem(t_stack **stack);
void	push_back(t_stack **stack, t_stack *elem);

/* Utils */
void	print_stack(t_stack *stack, const char *stack_name);
void	free_stack(t_stack *stack);
int		contains(t_stack *stack, int value);

#endif
