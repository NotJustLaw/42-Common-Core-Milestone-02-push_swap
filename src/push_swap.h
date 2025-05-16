/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:44:01 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/16 17:54:03 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h" 

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				nb;
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
	int				index;
}	t_list;

//Main functions
int		security_measure(int ac, char *av[], int **numbers, int *count);
int		splitter_and_error_handler(char **av, int **numbers, int *count);
int		error_handler(const char *s);
void	free_split(char **arr);
int		duplicate_checker(int *numbers, int count);

//Helpers
long	ft_strol(const char *s);
int		ft_is_space(char c);

//Stack Related
t_list	*stack_init(int	*numbers, int count);

//swap-ops
void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack_a, t_list *stack_b);
//push-ops
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
//rotate-ops
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
//reverse-rotate-ops
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
#endif