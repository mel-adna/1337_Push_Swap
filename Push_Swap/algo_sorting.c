/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:24:11 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/22 10:32:05 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*big_n;

	big_n = find_max_node(*a);
	if (big_n == *a && ft_stacksize(*a) == 3)
		ra(a);
	else if ((*a)->next == big_n && ft_stacksize(*a) == 3)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static int	find_min_position(t_stack *stack)
{
	int	min_pos;
	int	min_val;
	int	pos;

	pos = 0;
	min_pos = 0;
	min_val = stack->value;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack **stack)
{
	int	min_pos;
	int	len;

	min_pos = find_min_position(*stack);
	len = ft_stacksize(*stack);
	if (min_pos <= len / 2)
		while (min_pos--)
			ra(stack);
	else
		while (min_pos++ < len)
			rra(stack);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stacksize(*a);
	if (len > 5 || len < 4)
		return ;
	move_min_to_top(a);
	pb(a, b);
	if (len == 5)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	if (len == 5)
		pa(a, b);
}
