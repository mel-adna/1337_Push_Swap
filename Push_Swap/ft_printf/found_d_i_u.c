/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_d_i_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:20:13 by mel-adna          #+#    #+#             */
/*   Updated: 2024/11/20 20:22:56 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	found_d_i_u(long n, int count)
{
	if (n == 0)
	{
		count = found_c('0', count);
		return (count);
	}
	if (n < 0)
	{
		count = found_c('-', count);
		n = -n;
	}
	if (n >= 10)
		count = found_d_i_u(n / 10, count);
	count = found_c(n % 10 + '0', count);
	return (count);
}
