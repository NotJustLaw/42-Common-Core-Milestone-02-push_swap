/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:46:02 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/16 17:12:00 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//We use a pointer temp, bc thats the node that we will be changing, despite of that we work with double pointer to change the heads
static void	px(t_list **stack_dest, t_list **stack_src)
{
	t_list	*tmp;
	
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

void	pa(t_list **stack_a, t_list **stack_b)
{
	px(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	px(stack_b, stack_a);
	write(1, "pb\n", 3);
}