/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:51:40 by truello           #+#    #+#             */
/*   Updated: 2024/01/15 14:28:37 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_error(void)
{
	ft_printf("Error\n");
}

static int	exec_push(t_stack **a, t_stack **b)
{
	if (*a != NULL)
		push(a, pop(b));
	return (1);
}

static int	exec_instruction(t_stack **a, t_stack **b, char *instr)
{
	if (ft_strcmp(instr, "sa\n"))
		return (swap(a), 1);
	else if (ft_strcmp(instr, "sb\n"))
		return (swap(b), 1);
	else if (ft_strcmp(instr, "ra\n"))
		return (rotate(a), 1);
	else if (ft_strcmp(instr, "rb\n"))
		return (rotate(b), 1);
	else if (ft_strcmp(instr, "rr\n"))
		return (rotate(a), rotate(b), 1);
	else if (ft_strcmp(instr, "rra\n"))
		return (reverse_rotate(a), 1);
	else if (ft_strcmp(instr, "rrb\n"))
		return (reverse_rotate(b), 1);
	else if (ft_strcmp(instr, "rrr\n"))
		return (reverse_rotate(a), reverse_rotate(b), 1);
	else if (ft_strcmp(instr, "pa\n"))
		return (exec_push(a, b));
	else if (ft_strcmp(instr, "pb\n"))
		return (exec_push(b, a));
	return (0);
}

static void	exec_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_instruction(a, b, line))
			return (free(line), ft_printf("Error\n"), (void) 0);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a, SORT_ASCEND, stack_len(*a)) && stack_len(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
					return (print_error(), free_stack(a), 1);
			}
			else
				return (print_error(), free_stack(a), 1);
		}
		exec_instructions(&a, &b);
	}
	return (free_stack(a), free_stack(b), 0);
}
