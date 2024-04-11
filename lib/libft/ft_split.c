/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:09:41 by emgul             #+#    #+#             */
/*   Updated: 2023/12/10 22:35:47 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	word_count;

	if (!*s)
		return (0);
	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != c)
			s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_length;
	int		i;

	result = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (ft_strchr((char *)s, c))
				word_length = ft_strchr((char *)s, c) - s;
			else
				word_length = ft_strlen(s);
			result[i++] = ft_substr(s, 0, word_length);
			s += word_length;
		}
	}
	result[i] = NULL;
	return (result);
}
