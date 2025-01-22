/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:31:37 by mel-adna          #+#    #+#             */
/*   Updated: 2025/01/22 10:31:38 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*readline(int fd, char *rest);
void	free_str(char **str);
char	*extract_line(char *rest);
char	*up_rest(char **rest);
int		gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(const char *s);
int		gnl_strchr(const char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#endif