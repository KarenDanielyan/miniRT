/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:15:59 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/13 00:45:29 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_darray_init(t_darray *arr, size_t elem_size, size_t capacity)
{
	arr->nmemb = 0;
	arr->size = elem_size;
	arr->capacity = capacity;
	arr->content = ft_calloc(capacity, elem_size);
}

void	ft_darray_pushback(t_darray *arr, void *content)
{
	void	*tmp;

	if (arr->nmemb == arr->capacity)
	{
		tmp = arr->content;
		arr->capacity *= 2;
		arr->content = ft_calloc(arr->capacity, arr->size);
		ft_memcpy(arr->content, tmp, arr->nmemb * arr->size);
		free(tmp);
	}
	ft_memcpy((char *)(arr->content + (arr->nmemb * arr->size)), \
		content, arr->size);
	arr->nmemb++;
}

void	*ft_darray_get(t_darray *arr, void *value, int (*cmp)(void *a, void *b))
{
	size_t	i;

	i = 0;
	if (arr && cmp)
	{
		while (i < arr->size)
		{
			if (cmp((char *)(arr->content + i * arr->size), value))
				return ((char *)(arr->content + i * arr->size));
		}
	}
	return (NULL);
}

void	*ft_darray_get_by_index(t_darray *arr, int index)
{
	return (arr->content + (arr->size * index));
}

/* NOTE: del() is for freeing the memory for the fields inside the elements 
	of the array, not the elements themselves!!!!
*/
void	ft_darray_free(t_darray *arr, void (*del)(void *content))
{
	size_t	i;

	i = 0;
	if (arr)
	{
		if (del)
		{
			while (i < arr->nmemb)
			{
				del(ft_darray_get_by_index(arr, i));
				i ++;
			}
		}
		free(arr->content);
		arr->capacity = 0;
		arr->nmemb = 0;
		arr->size = 0;
		arr->content = NULL;
	}
}
