/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:20:20 by mel-adna          #+#    #+#             */
/*   Updated: 2024/11/20 20:38:39 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	found_s(char *s, int count)
{
	if (!s)
		count = found_s("(null)", count);
	else
	{
		while (*s)
		{
			write(1, &(*s), 1);
			count++;
			s++;
		}
	}
	return (count);
}
