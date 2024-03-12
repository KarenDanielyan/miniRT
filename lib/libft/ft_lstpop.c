/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:23:49 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/12 17:42:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param lst 
 * @param to_pop 
 * @param del 
 * 
 * NOTE: It's undefined whether to_pop is not present ins the list.
 */
void	ft_lstpop(t_list **lst, t_list *to_pop, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp && tmp->next != to_pop)
			tmp = tmp->next;
		prev = tmp;
		next = to_pop->next;
		if (prev == NULL)
			*lst = next;
		else
			prev->next = next;
		ft_lstdelone(to_pop, del);
	}
}
