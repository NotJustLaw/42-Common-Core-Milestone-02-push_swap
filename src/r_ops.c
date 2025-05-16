/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:45:59 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/16 17:39:54 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rx(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = (*stack);
	last = ft_lstlast(*stack);
	(*stack) = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rx(stack_a);
	rx(stack_b);
	write(1, "rr\n", 3);
}

void	ra(t_list **stack)
{
	rx(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rx(stack);
	write(1, "rb\n", 3);
}
