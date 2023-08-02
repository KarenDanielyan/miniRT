/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:24:48 by kdaniely          #+#    #+#             */
/*   Updated: 2023/01/14 22:34:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Reference: <bsd/string.h>
*
*	Description: ft_strlcpy copies up to size - 1 characters
*	from the NUL-terminated	string src to dst, NUL-terminating the result.
*
*	Return Value: ft_strlcpy returns the total length 
*	of the string they tried to create.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (i < (size - 1) && *(src + i))
		{
			*(dst + i) = *(src + i);
			i ++;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}
