/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:04:04 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/21 17:57:04 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestacks(t_stack **a, t_stack **b)
{
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
	*a = NULL;
	*b = NULL;
}

static void	check_error(char **split, t_stack **a)
{
	free_arg(split);
	if (*a)
		free_stack(a);
	error_exit();
}

static void	check_arg(char **argv, t_stack **a)
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
				check_error(split, a);
			if (ft_atol(split[j]) > INT_MAX || ft_atol(split[j]) < INT_MIN)
				check_error(split, a);
			if (split[j][0] == '-' || split[j][0] == '+')
				if (split[j][1] == '\0')
					check_error(split, a);
			add_back(a, ft_atol(split[j++]));
		}
		i++;
	}
	if (check_duplicates(*a))
		error_stack(a, NULL);
	free_arg(split);
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
			return (freestacks(&a, &b), 0);
		else if (ft_stacksize(a) <= 3)
			sort_three(&a);
		else if (ft_stacksize(a) <= 5)
			sort_five(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	else
		return (freestacks(&a, &b), 1);
	freestacks(&a, &b);
	system("leaks push_swap");
	return (0);
}
