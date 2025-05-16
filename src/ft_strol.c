/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:17:20 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/16 17:43:43 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_sign(const char *s, int *i);
static long	ft_parse_digits(const char *s, int *i, int sign);

long	ft_strol(const char *s)
{
	int		i;
	int		sign;
	long	res;

	if (!s)
		return (0);
	i = 0;
	while (ft_is_space(s[i]))
		i++;
	sign = ft_get_sign(s, &i);
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	res = ft_parse_digits(s, &i, sign);
	while (ft_is_space(s[i]))
		i++;
	if (s[i] != '\0')
		return (0);
	return (res * sign);
}

int	ft_is_space(char c)
{
	if (c == ' ' || (c > 7 && c < 15))
		return (1);
	return (0);
}

static int	ft_get_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static long	ft_parse_digits(const char *s, int *i, int sign)
{
	long	res;

	res = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		if (sign == 1)
		{
			if (res > (LONG_MAX - (s[*i] - '0')) / 10)
				return (LONG_MAX);
		}
		else
		{
			if (res > (-(LONG_MIN + (s[*i] - '0'))) / 10)
				return (LONG_MIN);
		}
		res = res * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (res);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *tests[] = {
// 		"   -42",
// 		" +123",
// 		"0",
// 		"   007   ",
// 		"no digits",
// 		"42abc",
// 		"",
// 		"   +0",
// 		"  21470000000000000483647",
// 		"  -2147483648",
// 		NULL
// 	};
// 	int i = 0;
// 	while (tests[i])
// 	{
// 		long result = ft_strol(tests[i]);
// 		printf("Input: '%s' -> Result: %ld\n", tests[i], result);
// 		i++;
// 	}
// 	return 0;
// }