/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:07:02 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/20 11:47:56 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_arr(t_stack *stack, int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	clone_stack(stack, arr);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	set_index(t_stack **stack, int len)
{
	int		i;
	int		*arr;
	t_stack	*tmp;

	tmp = *stack;
	arr = malloc(len * sizeof(int));
	if (!arr)
		return ;
	sort_arr(*stack, arr, len);
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == tmp->value)
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

void	ft_range(t_stack **a, t_stack **b)
{
	int	range_min;
	int	range_max;

	range_min = 0;
	if (ft_stacksize(*a) > 15)
		range_max = 0.045 * ft_stacksize(*a) + 10;
	else
		range_max = 0.045 * ft_stacksize(*a);
	while (*a)
	{
		if ((*a)->index > range_max)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->index < range_min)
				rb(b);
			range_min++;
			range_max++;
		}
	}
}

static int	max_v(t_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = ft_stacksize(stack) - 1;
	while (stack)
	{
		if (index == stack->index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (index);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size;
	int	index;

	size = ft_stacksize(*a);
	set_index(a, size);
	ft_range(a, b);
	while (*b)
	{
		size = ft_stacksize(*b);
		index = max_v(*b);
		if (index == 0)
			pa(a, b);
		else if (index > (size / 2) && index != 0)
			rrb(b);
		else if (index <= (size / 2) && index != 0)
			rb(b);
	}
	free_stack(a);
}
