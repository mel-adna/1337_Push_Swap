/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:01:00 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/21 17:55:03 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_stack(t_stack **a, t_stack **b)
{
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
	
	error_exit();
}

void	free_arg(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
}

void	add_back(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_exit();
	new->value = value;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int	ft_stacksize(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
