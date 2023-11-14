/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:11:13 by truello           #+#    #+#             */
/*   Updated: 2023/11/14 16:27:43 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_isint(long n)
{
	return (n >= INT32_MIN && n <= INT32_MAX);
}

static t_bool	contains(int *array, int start, int stop, int value)
{
	while (--start > stop)
	{
		if (array[start] == value)
			return (FT_TRUE);
	}
	return (FT_FALSE);
}

t_int_array	list_atoi(char **num_str)
{
	size_t		len;
	int			*integers;
	t_int_array	array;

	len = 0;
	while (num_str[len])
		len++;
	array.len = len;
	integers = (int *) ft_calloc(len, sizeof(int));
	while (len-- > 0)
	{
		integers[len] = ft_atoi(num_str[len]);
		if (contains(integers, array.len, len, integers[len]))
		{
			free(integers);
			array.array = NULL;
			return (array);
		}
	}
	array.array = integers;
	return (array);
}
