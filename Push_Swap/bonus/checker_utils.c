/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:31:42 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/22 10:31:43 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_arg_len(char **arg)
{
	int	i;

	i = 0;
	while (arg[i][0] == ' ' || arg[i][0] == '\t')
		arg[i]++;
	if (!arg[i][0])
		error_exit();
	return (1);
}

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
	while (argv[i] && (check_arg_len(&argv[i])))
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
