/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:31:50 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/21 21:24:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"

void	check_args(char **argv, t_stack **a);
void	push(t_stack **src, t_stack **dst);
void	reverse_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **stack);
void	swap_ss(t_stack **a, t_stack **b);
void	rotate_rr(t_stack **a, t_stack **b);
void	reverse_rotate_rrr(t_stack **a, t_stack **b);

#endif