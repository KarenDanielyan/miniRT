/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:20:05 by kdaniely          #+#    #+#             */
/*   Updated: 2023/07/09 19:41:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_before_alloc(char **strings, int i);
static char	*get_word(char const *str, char *delimiter);

static int	ft_strlen_delim(char const *str, char *delimiter);
static int	count_splits(char const *str, char *delimiter);

char	**ft_split_2(char const *s, char *charset)
{
	char	**strings;
	int		i;

	i = 0;
	strings = malloc((count_splits(s, charset) + 1) * sizeof(char *));
	while (*s)
	{
		while (*s && ft_strchr(charset, *s))
			s++;
		if (*s)
		{
			*(strings + i) = get_word(s, charset);
			if (!*(strings + i))
				return (free_before_alloc(strings, i));
			i++;
		}
		while (*s && !ft_strchr(charset, *s))
			s++;
	}
	*(strings + i) = 0;
	return (strings);
}

static int	ft_strlen_delim(char const *str, char *delimiter)
{
	int	i;

	i = 0;
	while (*(str + i) && !ft_strchr(delimiter, *(str + i)))
	{
		i++;
	}
	return (i);
}

static int	count_splits(char const *str, char *delimiter)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		while (*(str + i) && ft_strchr(delimiter, *(str + i)))
			i++;
		if (*(str + i))
			count++;
		while (*(str + i) && !ft_strchr(delimiter, *(str + i)))
			i++;
	}
	return (count);
}

static char	*get_word(char const *str, char *delimiter)
{
	int		word_len;
	int		i;
	char	*word;

	i = 0;
	word_len = ft_strlen_delim(str, delimiter);
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < word_len)
	{
		*(word + i) = *(str + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}

static char	**free_before_alloc(char **strings, int i)
{
	while (--i)
		free(strings[i]);
	free(strings);
	return (NULL);
}
