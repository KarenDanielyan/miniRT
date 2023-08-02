/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:06:19 by kdaniely          #+#    #+#             */
/*   Updated: 2023/01/21 16:24:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Reference: DNE
*
*	Description: Allocates (with malloc()) and returns a copy of
*	’s1’ with the characters specified in ’set’ removed
*	from the beginning and the end of the string.
*
*	Return Value: Allocated string, NULL if alloc fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*b;
	char	*e;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	b = (char *)s1;
	e = (char *)(s1 + ft_strlen(s1) - 1);
	while (*b && ft_strchr(set, *b))
		b++;
	while (e >= b && ft_strchr(set, *e))
		e--;
	trim = ft_substr(s1, (b - s1), (e - b + 1));
	if (!trim)
		return (NULL);
	return (trim);
}
