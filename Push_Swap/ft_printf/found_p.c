/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:20:16 by mel-adna          #+#    #+#             */
/*   Updated: 2024/11/21 12:59:14 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	found_p(void *p, int count)
{
	unsigned long	address;
	int				i;
	char			hex[16];
	char			hex_chars[17];

	ft_strcpy(hex_chars, "0123456789abcdef");
	address = (unsigned long)p;
	count = found_c('0', count);
	count = found_c('x', count);
	if (address == 0)
		return (found_c('0', count));
	i = 15;
	while (address > 0 && i >= 0)
	{
		hex[i] = hex_chars[address % 16];
		address /= 16;
		i--;
	}
	while (++i < 16)
		count = found_c(hex[i], count);
	return (count);
}
