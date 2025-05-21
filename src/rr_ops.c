/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:45:57 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 17:00:22 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrx(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	prev = last->prev;
	if (prev)
	{
		prev->next = NULL;
		last->prev = NULL;
	}
	else
	{
		return ;
	}
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}

void	rra(t_stack **stack)
{
	rrx(stack);
}

void	rrb(t_stack **stack)
{
	rrx(stack);
}
