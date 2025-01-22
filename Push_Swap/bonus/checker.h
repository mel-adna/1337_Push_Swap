/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:31:48 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/22 10:31:49 by mel-adna         ###   ########.fr       */
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