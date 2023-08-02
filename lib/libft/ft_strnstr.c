/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:16:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/01/20 19:42:43 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*bg;

	if ((!big ^ !little) && !len)
		return (NULL);
	bg = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)bg);
	while (*bg && len)
	{
		if ((*bg == *little) && (ft_strncmp(bg, little, little_len) == 0)
			&& (len >= little_len))
			return (bg);
		bg++;
		len--;
	}
	return (NULL);
}
