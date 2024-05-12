/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:00:53 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/12 20:38:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_if_ambient(void *l)
{
	if (((t_light *)l)->type == AMBIENT)
		return (true);
	return (false);
}

int	get_if_point(void *l)
{
	if (((t_light *)l)->type == POINT)
		return (true);
	return (false);
}
