/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:15:32 by truello           #+#    #+#             */
/*   Updated: 2023/11/13 15:51:06 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	check_numbers(char **nums)
{
	int	i;

	i = 0;
	if (nums[0] == NULL)
		return (FT_FALSE);
	while (nums[i])
	{
		if (ft_strlen(nums[i]) > 10 || !ft_isnum(nums[i]))
			return (FT_FALSE);
		if (!ft_isint(ft_atol(nums[i])))
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}

int	main(int ac, char **av)
{
	char	**nums;

	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		if (check_numbers(nums))
		{
			ft_printf("Num correct\n");
		}
		else
		{
			ft_printf("Num incorrect\n");
		}
	}
	return (0);
}
