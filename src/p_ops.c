/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:46:02 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 13:57:37 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//We use a pointer temp, bc thats the node that we will be changing, despite of that we work with double pointer to change the heads
static void	px(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*tmp;
	
	if (!stack_src || !*stack_src)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	tmp->next = *stack_dest;
	if (*stack_dest)
		(*stack_dest)->prev = NULL;	
	*stack_dest = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	px(stack_a, stack_b);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	px(stack_b, stack_a);
}