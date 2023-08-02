/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:51:09 by kdaniely          #+#    #+#             */
/*   Updated: 2023/01/21 16:25:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **split, int index)
{
	while (index--)
		free(*(split + index));
	free(split);
}

int	ft_strlen_delim(const char *str, char delimiter)
{
	int	i;

	i = 0;
	while (*(str + i) && (*(str + i) != delimiter))
	{
		i++;
	}
	return (i);
}

int	count_splits(const char *str, char delimiter)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		while (*(str + i) && (*(str + i) == delimiter))
			i++;
		if (*(str + i))
			count++;
		while (*(str + i) && (*(str + i) != delimiter))
			i++;
	}
	return (count);
}

char	**get_strings(char **strings, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(s + j))
	{
		while (*(s + j) && (*(s + j) == c))
			j++;
		if (*(s + j))
		{
			*(strings + i) = ft_substr(s, j, ft_strlen_delim((s + j), c));
			if (!*(strings + i))
			{
				free_split(strings, i);
				return (NULL);
			}
			i++;
		}
		while (*(s + j) && (*(s + j) != c))
			j++;
	}
	*(strings + i) = 0;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	strings = get_strings(strings, s, c);
	if (!strings)
		return (NULL);
	return (strings);
}
