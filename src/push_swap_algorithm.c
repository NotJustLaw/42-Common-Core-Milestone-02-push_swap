/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:26:04 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 14:09:32 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_op **log)
{
	exec_op(a, NULL, log, "sa");
}

void	sort_three(t_stack **a, t_op **log)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->content;
	n2 = (*a)->next->content;
	n3 = (*a)->next->next->content;
	if (n1 < n2 && n2 < n3)
		return ;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		exec_op(a, NULL, log, "sa");
	else if (n1 > n2 && n2 > n3)
	{
		exec_op(a, NULL, log, "sa");
		exec_op(a, NULL, log, "rra");
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		exec_op(a, NULL, log, "ra");
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		exec_op(a, NULL, log, "sa");
		exec_op(a, NULL, log, "ra");
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		exec_op(a, NULL, log, "rra");
}

static int	min_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*tmp;
	
	min = a->content;
	pos = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	sort_four(t_stack **a, t_stack **b, t_op **log)
{
	int pos;
	int size;

	size = stack_size(*a);
	pos = min_pos(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			exec_op(a, NULL, log, "ra");
	else
		while (pos++ < size)
			exec_op(a, NULL, log, "rra");
	exec_op(a, b, log, "pb");
	sort_three(a, log);
	exec_op(a, b, log, "pa");
}

void	sort_five(t_stack **a, t_stack **b, t_op **log)
{
	int	pos;
	int	size;

	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		pos = min_pos(*a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				exec_op(a, NULL, log, "ra");
		}
		else
		{
			while (pos++ < size)
				exec_op(a, NULL, log, "rra");
		}
		exec_op(a, b, log, "pb");
	}
	sort_three(a, log);
	while (*b)
		exec_op(a, b, log, "pa");
}
