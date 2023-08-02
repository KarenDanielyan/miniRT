/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:03:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/01/18 21:21:31 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Reference: DNE
*
*	Description: Applies the function ’f’ to each character of the
*	string ’s’, and passing its index as first argument
*	to create a new string (with malloc()) resulting
*	from successive applications of ’f’.
*
*	Return Value: Resulted string, NULL if allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		len;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	map = (char *)malloc(len + 1);
	if (!map)
		return (NULL);
	while (i < len)
	{
		*(map + i) = (*f)(i, *(s + i));
		i ++;
	}
	*(map + i) = '\0';
	return (map);
}
