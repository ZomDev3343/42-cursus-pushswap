/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:17 by truello           #+#    #+#             */
/*   Updated: 2023/12/05 11:52:57 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	ft_printf("Error\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		while (++i < ac)
		{
			if (av[i][0] != '\0' && is_int(av[i]))
			{
				if (!push_int(av[i], &a))
					return (print_error(), free_stack(a), 0);
			}
			else
				return (print_error(), free_stack(a), 0);
		}
		if (!is_sorted(a, SORT_ASCEND, stack_len(a)))
			quicksort_a(&a, &b, stack_len(a), 0);
	}
	return (free_stack(a), free_stack(b), 0);
}
