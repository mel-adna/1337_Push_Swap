/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:57:04 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/19 14:45:07 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_node(t_stack *a)
{
	int		max;
	t_stack	*tmp;
	t_stack	*max_node;

	tmp = a;
	max = tmp->value;
	max_node = tmp;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	clone_stack(t_stack *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
}
