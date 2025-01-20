/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:29:34 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/20 13:31:40 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	stack_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	operation(char *line, t_stack **a, t_stack **b)
{
	if (stack_strncmp(line, "sa", 2) == 0)
		swap(a);
	else if (stack_strncmp(line, "sb", 2) == 0)
		swap(b);
	else if (stack_strncmp(line, "ss", 2) == 0)
		swap_ss(a, b);
	else if (stack_strncmp(line, "pa", 2) == 0)
		push(b, a);
	else if (stack_strncmp(line, "pb", 2) == 0)
		push(a, b);
	else if (stack_strncmp(line, "ra", 2) == 0)
		rotate(a);
	else if (stack_strncmp(line, "rb", 2) == 0)
		rotate(b);
	else if (stack_strncmp(line, "rra", 3) == 0)
		reverse_rotate(a);
	else if (stack_strncmp(line, "rrb", 3) == 0)
		reverse_rotate(b);
	else if (stack_strncmp(line, "rrr", 3) == 0)
		reverse_rotate_rrr(a, b);
	else if (stack_strncmp(line, "rr", 2) == 0)
		rotate_rr(a, b);
	else
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

int	operation_checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (operation(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (argv[1] == NULL)
		return (1);
	if (argc >= 2)
	{
		check_args(argv, &a);
		if (operation_checker(&a, &b) == 0)
			ft_putstr_fd("KO\n", 2);
		else
		{
			if (is_sorted(a) && !b)
				ft_putstr_fd("OK\n", 2);
			else
				ft_putstr_fd("KO\n", 2);
		}
	}
	else
		return (1);
	free_stack(&a);
}
