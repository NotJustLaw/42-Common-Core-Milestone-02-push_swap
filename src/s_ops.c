/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:24:08 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/16 17:11:35 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
static void	sx(t_list *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sx(stack_a);
	sx(stack_b);
	write(1, "ss\n", 3);
}

void	sa(t_list *stack)
{
	sx(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list *stack)
{
	sx(stack);
	write(1, "sb\n", 3);
}
