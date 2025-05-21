/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:45:59 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 13:57:20 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rx(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = (*stack);
	last = stack_last(*stack);
	(*stack) = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rx(stack_a);
	rx(stack_b);
}

void	ra(t_stack **stack)
{
	rx(stack);
}

void	rb(t_stack **stack)
{
	rx(stack);
}
