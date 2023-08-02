/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:00:25 by kdaniely          #+#    #+#             */
/*   Updated: 2023/06/30 18:24:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Reference: <string.h>
*
*	Desription: strdup creates a new string which is a duplicate
*	of the string s. Memory for the new string is obtained with
*	malloc(), and can be freed with free().
*
*	Return Value: On success, ft_strdup returns a pointer to
*	the duplicated string. It returns NULL if insufficient
*	memory was available.
*/
char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = NULL;
	if (s)
	{
		dup = malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!dup)
			return (NULL);
		while (*(s + i))
		{
			*(dup + i) = *(s + i);
			i ++;
		}
		*(dup + i) = '\0';
	}
	return (dup);
}
