/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:17:27 by truello           #+#    #+#             */
/*   Updated: 2023/11/28 14:46:23 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if a string is a number or a list of multiple numbers */
int	is_int(char *str)
{
	char	**parts;
	int		i;
	long	n;

	i = -1;
	parts = ft_split(str, ' ');
	while (parts[++i])
	{
		n = ft_atol(parts[i]);
		if (ft_strlen(parts[i]) > 11 || (n > INT32_MAX || n < INT32_MIN)
			|| (n == 0 && !ft_strcmp(parts[i], "0")))
			return (FALSE);
	}
	free(parts);
	return (TRUE);
}

void	push_int(char *str, t_stack *stack)
{

}
