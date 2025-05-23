/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:25:35 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/23 12:49:41 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_op(t_op **log, char *op)
{
	t_op	*new;
	t_op	*tmp;

	new = malloc(sizeof(t_op));
	if (!new)
	{
		exit(1);
	}
	new->name = ft_strdup(op);
	if (!new->name)
	{
		free(new);
		exit(1);
	}
	new->next = NULL;
	if (!*log)
		*log = new;
	else
	{
		tmp = *log;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_op	*last_op(t_op *log)
{
	t_op	*tmp;

	if (!log)
		return (NULL);
	tmp = log;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next)
		return (tmp->next);
	else
		return (NULL);
}

void	print_ops(t_op *log)
{
	while (log)
	{
		write(1, log->name, ft_strlen(log->name));
		write(1, "\n", 1);
		log = log->next;
	}
}

void	free_op_log(t_op *log)
{
	t_op	*tmp;

	while (log)
	{
		tmp = log->next;
		if (log->name)
			free(log->name);
		free(log);
		log = tmp;
	}
}
