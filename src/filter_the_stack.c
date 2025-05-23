/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_the_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:20:28 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/23 12:46:51 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_op(t_stack **a, t_stack **b, t_op **log, char *op)
{
	t_op	*last;

	last = last_op(*log);
	add_op(log, op);
	if (ft_strcmp(op, "sa") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss") == 0)
	{
		sa(a);
		sb(b);
	}
	else if (ft_strcmp(op, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		pb(b, a);
	else
		exec_rotate_ops(a, b, op);
}

void	exec_rotate_ops(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb") == 0)
		rb(b);
	else if (ft_strcmp(op, "rr") == 0)
	{
		ra(a);
		rb(b);
	}
	else if (ft_strcmp(op, "rra") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		rra(a);
		rrb(b);
	}
}
