/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:38:56 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/23 12:44:24 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sorter(t_stack **a, t_stack **b, t_op **log)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a, log);
	else if (size == 3)
		sort_three(a, log);
	else if (size == 4)
		sort_four(a, b, log);
	else if (size == 5)
		sort_five(a, b, log);
	else
		radix_sort(a, b, log);
}

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	max_bits;

	max_bits = 0;
	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b, t_op **log)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;
	t_stack	*tmp;

	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			tmp = *a;
			if (((tmp->index >> i) & 1) == 0)
				exec_op(a, b, log, "pb");
			else
				exec_op(a, NULL, log, "ra");
			j++;
		}
		while (*b)
			exec_op(a, b, log, "pa");
		i++;
	}
}
