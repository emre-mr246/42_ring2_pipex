/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:01:13 by emgul             #+#    #+#             */
/*   Updated: 2024/02/09 23:58:02 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_append_to_left(int fd, char *input_str);
char	*ft_get_line(char *input_str);
char	*ft_extract_after_newline(char *input_str);
size_t	ft_strlen_gnl(const char *result);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *left_str, char *buff);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

#endif
