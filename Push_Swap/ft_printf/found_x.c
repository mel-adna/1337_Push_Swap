/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:20:23 by mel-adna          #+#    #+#             */
/*   Updated: 2024/11/21 09:56:25 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	found_x(size_t x, int count, char base)
{
	if (x == 0)
	{
		count = found_c('0', count);
		return (count);
	}
	else if (x >= 16)
	{
		count = found_x(x / 16, count, base);
		count = found_x(x % 16, count, base);
	}
	else
	{
		if (x <= 9)
			count = found_c(x + '0', count);
		else
			count = found_c(x + base - 10, count);
	}
	return (count);
}
