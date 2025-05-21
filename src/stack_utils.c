/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:57:44 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 12:48:20 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*stack_last(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = stack_last(*lst);
	last->next = new;
}

t_stack	*stack_new(int nb)
{
	t_stack	*part;

	part = malloc(sizeof(t_stack));
	if (!part)
		return (NULL);
	part->content = nb;
	part->next = NULL;
	part->prev = NULL;
	return (part);
}