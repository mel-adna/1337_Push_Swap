/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:04:04 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/22 10:33:25 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	check_arg(char **argv, t_stack **a)
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

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		if (!argv[1][0] || argv[1][0] == '\0')
			error_exit();
		check_arg(argv, &a);
		if (is_sorted(a))
			return (free_stack(&a), 0);
		else if (ft_stacksize(a) <= 3)
			sort_three(&a);
		else if (ft_stacksize(a) <= 5)
			sort_five(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	else
		return (1);
	free_stack(&a);
	return (0);
}
