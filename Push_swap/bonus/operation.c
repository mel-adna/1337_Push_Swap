/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:19 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/20 13:34:20 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if ((*dst))
		(*dst)->prev = tmp;
	*dst = tmp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = last;
	last->next = first;
	first->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

void	reverse_rotate_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
