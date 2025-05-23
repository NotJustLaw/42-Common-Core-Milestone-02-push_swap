/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:24:08 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/23 12:42:09 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sx(t_stack **stack)
{
	int	tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sx(stack_a);
	sx(stack_b);
}

void	sa(t_stack **stack)
{
	sx(stack);
}

void	sb(t_stack **stack)
{
	sx(stack);
}
