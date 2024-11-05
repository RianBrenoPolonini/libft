/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:47:19 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 12:57:56 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_set(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(const char *str, const char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && char_is_in_set(str[i], charset))
			i++;
		if (str[i] && !char_is_in_set(str[i], charset))
		{
			count++;
			while (str[i] && !char_is_in_set(str[i], charset))
				i++;
		}
	}
	return (count);
}

static char	*get_next_segment(const char *str, int *index, const char *charset)
{
	int		start;
	int		segment_length;

	start = *index;
	segment_length = 0;
	while (str[start] && char_is_in_set(str[start], charset))
		start++;
	*index = start;
	while (str[*index] && !char_is_in_set(str[*index], charset))
	{
		(*index)++;
		segment_length++;
	}
	return (ft_substr(str, start, segment_length));
}

char	**ft_split(const char *str, const char *charset)
{
	int		word_count;
	char	**result;
	int		index;
	int		i;

	word_count = count_words(str, charset);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	i = 0;
	index = 0;
	if (!result)
		return (NULL);
	while (i < word_count)
	{
		result[i] = get_next_segment(str, &index, charset);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
