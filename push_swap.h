/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:15 by truello           #+#    #+#             */
/*   Updated: 2023/11/28 15:50:46 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
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

/* Sort Utils */

int		is_sorted(t_stack *stack, int order);

/* Stack */

t_stack	*pop(t_stack **stack);
void	push(t_stack **stack, t_stack *elem);

#endif
