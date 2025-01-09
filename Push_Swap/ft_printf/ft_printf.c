/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:17:48 by mel-adna          #+#    #+#             */
/*   Updated: 2024/11/21 13:04:30 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	next_percent(const char *format, va_list args, int count, int i)
{
	if (format[i] == 'c')
		count = found_c(va_arg(args, int), count);
	else if (format[i] == 's')
		count = found_s(va_arg(args, char *), count);
	else if (format[i] == 'p')
		count = found_p(va_arg(args, void *), count);
	else if (format[i] == 'd' || format[i] == 'i')
		count = found_d_i_u(va_arg(args, int), count);
	else if (format[i] == 'u')
		count = found_d_i_u(va_arg(args, unsigned int), count);
	else if (format[i] == 'x')
		count = found_x(va_arg(args, unsigned int), count, 'a');
	else if (format[i] == 'X')
		count = found_x(va_arg(args, unsigned int), count, 'A');
	else if (format[i] == '%')
		count = found_c('%', count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	if (write(1, NULL, 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			count = next_percent(format, args, count, ++i);
		}
		else
			count = found_c(format[i], count);
		i++;
	}
	va_end(args);
	return (count);
}
