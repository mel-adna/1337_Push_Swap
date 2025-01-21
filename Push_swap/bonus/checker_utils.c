/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:32:08 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/21 21:42:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_error(char **split)
{
	free_arg(split);
	error_exit();
}

void	check_args(char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (is_str_not_number(split[j]))
				check_error(split);
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				check_error(split);
			if (split[j][0] == '-' || split[j][0] == '+')
				if (split[j][1] == '\0')
					check_error(split);
			add_back(a, ft_atol(split[j++]));
		}
		free_arg(split);
		i++;
	}
	if (check_duplicates(*a))
		error_stack(*a, NULL);
}

void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
	tmp2->prev = tmp->prev;
	tmp->prev = tmp2;
	*stack = tmp2;
}

void	swap_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
