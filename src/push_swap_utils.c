/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:44:05 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/16 17:45:05 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_numbers(char **av);
static int	fill_numbers(char **av, int *numbers, int *idx);

int	splitter_and_error_handler(char **av, int **numbers, int *count)
{
	int	idx;

	*count = count_numbers(av);
	if (*count <= 0)
		return (0);
	*numbers = malloc(sizeof(int) * (*count));
	if (!*numbers)
		return (0);
	idx = 0;
	if (!fill_numbers(av, *numbers, &idx))
	{
		free(*numbers);
		return (0);
	}
	return (1);
}

int	error_handler(const char *s)
{
	int i;

	i = 0;
	if (!s || !*s)
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	long val = ft_strol(s);
	if (val < INT_MIN || val > INT_MAX)
		return (1);
	return (0);
}

void	free_split(char **arr)
{
	int i = 0;
	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	count_numbers(char **av)
{
	int	i;
	int	count;
	char	**arr;
	int	j;

	count = 0;
	i = 0;
	while (av[++i])
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			return (-1);
		j = -1;
		while (arr[++j])
			count++;
		free_split(arr);
	}
	return (count);
}

int	fill_numbers(char **av, int *numbers, int *idx)
{
	int	i;
	int	j;
	char	**arr;
	long	val;

	i = 0;
	while (av[++i])
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			return (0);
		j = -1;
		while (arr[++j])
		{
			if (error_handler(arr[j]))
			{
				free_split(arr);
				return (0);
			}
			val = ft_strol(arr[j]);
			numbers[(*idx)++] = (int)val;
		}
		free_split(arr);
	}
	return (1);
}

