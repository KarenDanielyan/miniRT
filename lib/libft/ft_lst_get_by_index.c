/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_by_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:08:04 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 15:27:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_get_by_index(t_list *head, int index)
{
	int	counter;

	counter = 0;
	while (head)
	{
		if (index == counter)
			return (head);
		counter++;
		head = head->next;
	}
	return (NULL);
}
