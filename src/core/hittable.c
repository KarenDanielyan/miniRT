/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:27:09 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 16:59:16 by kdaniely         ###   ########.fr       */
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

bool	hit_anything(t_ray *r, t_darray *world, t_hitrecord *hr)
{
	size_t		i;
	t_hittable	*current;
	float		t;

	i = 0;
	while (i < world->nmemb)
	{
		current = ft_darray_get_by_index(world, i);
		t = current->hit(&current->shape, r);
		if (i == 0 || ((hr->t < 0.0 || t < hr->t) && t > 0.0))
		{
			hr->t = t;
			hr->at = ray_at(r, t);
			hr->hit = current;
		}
		i ++;
	}
	if (hr->t > __FLT_EPSILON__)
	{
		hr->normal = get_normal(&hr->at, hr->hit);
		return (true);
	}
	return (false);
}
