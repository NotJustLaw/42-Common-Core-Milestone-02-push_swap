/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:25:35 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 13:46:47 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_op(t_op **log, char *op)
{
	t_op *new = malloc(sizeof(t_op));
	new->name = ft_strdup(op);
	new->next = NULL;

	if (!*log)
		*log = new;
	else
	{
		t_op *tmp = *log;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_op	*last_op(t_op *log)
{
	t_op *tmp = log;
	if (!tmp) return NULL;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	return tmp->next ? tmp : NULL;
}

void	remove_last_op(t_op **log)
{
	t_op *tmp = *log;
	t_op *prev = NULL;

	if (!tmp)
		return ;
	if (!tmp->next)
	{
		free(tmp->name);
		free(tmp);
		*log = NULL;
		return ;
	}
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	free(tmp->name);
	free(tmp);
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
	t_op *tmp;

	while (log)
	{
		tmp = log->next;
		free(log->name);
		free(log);
		log = tmp;
	}
}