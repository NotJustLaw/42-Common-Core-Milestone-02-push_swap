/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:38:56 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/19 20:13:01 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_sorter(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a), printf("GOt into sort_four");
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	max_bits; 
	
	max_bits = 0;
	max = a->content;
	while (a)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
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
			if (((tmp->content >> i) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
