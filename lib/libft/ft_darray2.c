/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:53:39 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/20 17:05:41 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * 		ft_darray_get_if() will return the first occurent element of 
 *		array arr, that satify the condition specified by (*cmp).
*/
void	*ft_darray_get_if(t_darray *arr, int (*cmp)(void *value))
{
	void	*value;
	size_t	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (i < arr->nmemb)
	{
		value = ft_darray_get_by_index(arr, i);
		if (cmp(value) == 1)
			return (value);
		i ++;
	}
	return (NULL);
}
