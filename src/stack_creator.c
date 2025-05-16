/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:28:26 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/16 17:43:51 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_init(int	*numbers, int count)
{
	t_list	*stack_a;
	int		i;

	stack_a = NULL;
	i = -1;
	while (++i < count)
		ft_lstadd_back(&stack_a, ft_lstnew(numbers[i]));
	return (stack_a);
}
