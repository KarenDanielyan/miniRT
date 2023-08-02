/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:18:24 by kdaniely          #+#    #+#             */
/*   Updated: 2023/07/08 19:11:37 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (dest && src)
	{
		while (*(src + i))
		{
			*(dest + i) = *(src + i);
			i++;
		}
	}
}

/*
*	Reference: DNE
*
*	Description: Allocates (with malloc()) and returns a new
*	string, which is the result of the concatenation
*	of ’s1’ and ’s2’.
*
*	Return Value: The new string, NULL if allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join_strcpy(join, s1);
	join_strcpy(join + len1, s2);
	*(join + len1 + len2) = '\0';
	if (!(*join))
	{
		free(join);
		join = NULL;
	}
	return (join);
}
