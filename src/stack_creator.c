/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:28:26 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 13:02:03 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int	*numbers, int count)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = -1;
	while (++i < count)
		stackadd_back(&stack_a, stack_new(numbers[i]));
	return (stack_a);
}

static int	*stack_to_array(t_stack *a, int size)
{
	int	*arr;
	int	i;
	
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->index;
		a = a->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;
	
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void	index_stack(t_stack **a)
{
	int		*arr;
	int		i;
	int		size;
	t_stack	*tmp;
	
	size = stack_size(*a);
	arr = stack_to_array(*a, size);
	sort_array(arr, size);
	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->index == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
