/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:21:17 by tlai              #+#    #+#             */
/*   Updated: 2024/01/19 12:17:21 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_substr(char *str, char space)
{
	int		num_substr;
	bool	inside_word;

	num_substr = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == space)
			++str;
		while (*str != space && *str)
		{
			if (!inside_word)
			{
				++num_substr;
				inside_word = true;
			}
			++str;
		}
	}
	return (num_substr);
}

static char	*next_word(char *str, char space)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == space)
		++cursor;
	while ((str[cursor + len] != space) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != space) && str[cursor])
	{
		next_str[i] = str[cursor];
		i++;
		cursor++;
	}
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char space)
{
	int		num_substr;
	char	**substr_array;
	int		i;

	i = 0;
	num_substr = count_substr(str, space);
	if (!num_substr)
		exit(1);
	substr_array = malloc(sizeof(char *) * (size_t)(num_substr + 2));
	if (substr_array == NULL)
		return (NULL);
	while (num_substr-- >= 0)
	{
		if (i == 0)
		{
			substr_array[i] = malloc(sizeof(char));
			if (substr_array[i] == NULL)
				return (NULL);
			substr_array[i++][0] = '\0';
			continue ;
		}
		substr_array[i++] = next_word(str, space);
	}
	substr_array[i] = NULL;
	return (substr_array);
}
