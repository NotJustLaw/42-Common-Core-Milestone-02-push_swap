/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:44:01 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/19 19:59:18 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h" 

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
}	t_stack;

//Main functions
int		security_measure(int ac, char *av[], int **numbers, int *count);
int		splitter_and_error_handler(char **av, int **numbers, int *count);
int		error_handler(const char *s);
void	free_split(char **arr);
int		duplicate_checker(int *numbers, int count);

//Helpers
long	ft_strol(const char *s);
int		ft_is_space(char c);
void    free_stack(t_stack *stack);

//Stack Related
t_stack	*stack_init(int	*numbers, int count);
void	index_stack(t_stack **a);

//swap-ops
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
//push-ops
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
//rotate-ops
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
//reverse-rotate-ops
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//Sort Sorter
void	sort_sorter(t_stack **a, t_stack **b);

//Simple Algorithms
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

//Hard Algorithm
void	radix_sort(t_stack **a, t_stack **b);

//Stack utils
int		stack_size(t_stack *lst);
t_stack	*stack_last(t_stack *lst);
void	stackadd_back(t_stack **lst, t_stack *new);
t_stack	*stack_new(int nb);
#endif