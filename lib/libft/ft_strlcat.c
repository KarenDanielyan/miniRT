/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:46:26 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/09 17:59:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Reference: <bsd/string.h>
*	Description: The ft_strlcat() function appends 
*	the NUL-terminated string src to the end of dst.
*	It will append at most size - strlen(dst) - 1 bytes,
*	NUL-terminating the result.
*
*	Return Value: ft_strlcat() returns the total length
*	of the string it tried to create.
*	That means the initial length of dst plus the length of src.
*	However, if ft_strlcat() traverses size characters 
*	without finding a NUL, the length of the string is
*	considered to be size and the destination string
*	will not be NUL-terminated (since there was no space for the NUL).
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	if ((!dst || !src) && !size)
		return (0);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (size + ft_strlen(src));
	i = 0;
	while (*(src + i) && i + dest_len < size - 1)
	{
		*(dst + dest_len + i) = *(src + i);
		i++;
	}
	*(dst + dest_len + i) = '\0';
	return (dest_len + ft_strlen(src));
}
