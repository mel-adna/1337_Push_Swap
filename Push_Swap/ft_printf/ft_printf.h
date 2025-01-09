/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:39:39 by mel-adna          #+#    #+#             */
/*   Updated: 2024/11/23 11:30:00 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	found_c(int c, int count);
int	found_s(char *s, int count);
int	found_d_i_u(long d, int count);
int	found_x(size_t x, int count, char base);
int	found_p(void *p, int count);

#endif