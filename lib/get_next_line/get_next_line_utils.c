/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:01:00 by emgul             #+#    #+#             */
/*   Updated: 2024/04/11 00:15:57 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *result)
{
	size_t	len;

	len = 0;
	while (result[len])
		len++;
	return (len);
}

char	*ft_strchr_gnl(char *result, int c)
{
	if (!result)
		return (NULL);
	if ((unsigned char)c == 0)
		return (result + ft_strlen_gnl(result));
	while (*result)
	{
		if ((unsigned char)*result == (unsigned char)c)
			return ((char *)result);
		result++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *input_str, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	result_len;
	char	*result;

	result_len = ft_strlen_gnl(input_str) + ft_strlen_gnl(buffer);
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (input_str[++i])
		result[i] = input_str[i];
	while (buffer[j])
		result[i++] = buffer[j++];
	result[result_len] = '\0';
	free(input_str);
	return (result);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
