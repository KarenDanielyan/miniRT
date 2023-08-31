/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcountif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:47:15 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/31 15:48:43 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcountif(t_list *lst, int (*cmp)(void *content))
{
	int	i;

	i = 0;
	while (lst)
	{
		if (cmp(lst->content) == 1)
			i ++;
		lst = lst->next;
	}
	return (i);
}
