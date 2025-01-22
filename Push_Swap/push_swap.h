/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:03:03 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/22 10:32:14 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void	set_index(t_stack **stack, int len);
void	add_back(t_stack **stack, int value);
int		check_duplicates(t_stack *a);
void	error_exit(void);
int		is_str_not_number(char *str);
void	free_arg(char **split);
int		is_sorted(t_stack *a);
int		ft_stacksize(t_stack *a);
void	free_stack(t_stack **stack);
void	sort_three(t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	error_stack(t_stack *a, t_stack *b);
t_stack	*find_last(t_stack *stack);
t_stack	*find_max_node(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);
long	ft_atol(const char *str);
void	clone_stack(t_stack *stack, int *arr);

#endif