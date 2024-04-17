/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:27:09 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 17:43:15 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

void	*new_hittable(t_type type, t_hit hit, void *shape)
{
	t_hittable	*obj;

	obj = ft_calloc(1, sizeof(t_hittable));
	if (obj == NULL)
	{
		ft_printf("Fatal Error: Cannot allocate an object.\n");
		exit(EXIT_FAILURE);
	}
	obj->type = type;
	obj->hit = hit;
	if (type == SPHERE)
		obj->shape.s = *((t_sphere *)shape);
	return (obj);
}
