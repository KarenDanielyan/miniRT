/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:42:11 by kdaniely          #+#    #+#             */
/*   Updated: 2023/01/15 23:09:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Reference: <string.h>
*
*	Description: ft_memchr scans the initial n bytes of the
*	memory area pointed to by s for the first instance of c.
*
*	Return Value: Pointer to the matching byte or NULL if DNE.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buf;
	unsigned char	val;
	size_t			i;

	buf = (unsigned char *)s;
	val = (unsigned char)(c & 0xFF);
	i = 0;
	while (i < n)
	{
		if (*(buf + i) == val)
			return (buf + i);
		i++;
	}
	return (NULL);
}
