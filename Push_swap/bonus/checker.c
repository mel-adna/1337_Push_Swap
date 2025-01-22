/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:07:48 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/22 00:17:42 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

void	freestacks(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	while (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		free(tmp);
	}
	*a = NULL;
	*b = NULL;
}

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
	if (stack_strncmp(line, "sa\n", 3) == 0 && line[3] == '\0')
		swap(a);
	else if (stack_strncmp(line, "sb\n", 3) == 0 && line[3] == '\0')
		swap(b);
	else if (stack_strncmp(line, "ss\n", 3) == 0 && line[3] == '\0')
		swap_ss(a, b);
	else if (stack_strncmp(line, "pa\n", 3) == 0 && line[3] == '\0')
		push(b, a);
	else if (stack_strncmp(line, "pb\n", 3) == 0 && line[3] == '\0')
		push(a, b);
	else if (stack_strncmp(line, "ra\n", 3) == 0	&& line[3] == '\0')
		rotate(a);
	else if (stack_strncmp(line, "rb\n", 3) == 0 && line[3] == '\0')
		rotate(b);
	else if (stack_strncmp(line, "rr\n", 3) == 0 && line[3] == '\0')
		rotate_rr(a, b);
	else if (stack_strncmp(line, "rra\n", 4) == 0 && line[4] == '\0')
		reverse_rotate(a);
	else if (stack_strncmp(line, "rrb\n", 4) == 0 && line[4] == '\0')
		reverse_rotate(b);
	else if (stack_strncmp(line, "rrr\n", 4) == 0 && line[4] == '\0')
		reverse_rotate_rrr(a, b);
	else
		return (1);
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
			freestacks(a, b);
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
		if (!argv[1][0] || argv[1][0] == '\0')
			error_exit();
		check_args(argv, &a);
		if (operation_checker(&a, &b) == 0)
			error_exit();
		else
		{
			if (is_sorted(a) && !b)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
		}
	}
	else
		return (1);
	freestacks(&a , &b);
}
