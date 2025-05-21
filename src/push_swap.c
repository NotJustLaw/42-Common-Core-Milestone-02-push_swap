/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:44:03 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/20 13:51:32 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
    int 	*numbers;
    int 	count;
	t_stack	*stack_a; 
	t_stack	*stack_b;
	t_op	*log;

	numbers = NULL;
	count = 0;
	log = NULL;
    if (!security_measure(ac, av, &numbers, &count))
		return (1);
	stack_b = NULL;
	stack_a = stack_init(numbers, count);
	free(numbers);
	index_stack(&stack_a);
	sort_sorter(&stack_a, &stack_b, &log);
	print_ops(log);
	free_op_log(log);
	free_stack(stack_a);
	free_stack(stack_b);
    return (0);
}

int	security_measure(int ac, char *av[], int **numbers, int *count)
{
	if (ac < 2)
		return (0);
	if (!splitter_and_error_handler(av, numbers, count))
	{
		write(2, "Error\n", 6);
		if (*numbers)
			free(*numbers);
		return (0);
	}
	if (!duplicate_checker(*numbers, *count))
	{
		write(2, "Error\n", 6);
		free(*numbers);
		return (0);
	}
	return (1);
}

int	duplicate_checker(int *numbers, int count)
{
	int	i;
	int j;
	
	i = 0;
	while(i < count - 1)
	{
		j = i + 1;
		while(j < count)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void    free_stack(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack->next;
		stack->next = NULL;
		stack->prev = NULL;
		free(stack);
		stack = tmp;
	}
}