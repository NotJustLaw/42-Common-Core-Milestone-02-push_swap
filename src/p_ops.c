/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:46:02 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/23 12:42:57 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	px(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	tmp->prev = NULL;
	*dest = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	px(stack_a, stack_b);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	px(stack_b, stack_a);
}
