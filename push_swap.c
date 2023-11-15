/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:15:32 by truello           #+#    #+#             */
/*   Updated: 2023/11/15 15:26:14 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the arguments passed to the program are valid */
static t_bool	check_numbers(char **nums)
{
	int	i;

	i = 0;
	if (nums[0] == NULL)
		return (FT_FALSE);
	while (nums[i])
	{
		if (ft_strlen(nums[i]) > 11 || !ft_isnum(nums[i]))
			return (FT_FALSE);
		if (!ft_isint(ft_atol(nums[i])))
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}

/* Takes care of the pile sorting */
static t_bool	sort_stack(t_stack **a, t_stack **b, t_int_array array)
{
	int	i;

	if (array.array == NULL)
		return (FT_FALSE);
	i = -1;
	*b = NULL;
	while (++i < array.len)
		push(a, newstack(array.array[array.len - i - 1]));
	print_stack(*a);
	reverse_rotate(a);
	print_stack(*a);
	return (FT_TRUE);
}

int	main(int ac, char **av)
{
	char	**nums;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		if (check_numbers(nums))
		{
			if (!sort_stack(&a, &b, list_atoi(nums)))
				ft_error("Error\n");
		}
		else
		{
			ft_error("Error\n");
		}
		free_parts(nums);
	}
	return (0);
}
