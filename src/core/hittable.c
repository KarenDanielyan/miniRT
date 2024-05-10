/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:27:09 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 17:42:46 by kdaniely         ###   ########.fr       */
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
	t_hittable	*current;
	bool		hit_anything;
	size_t		i;
	double		t;

	i = 0;
	hr->t = __FLT_MAX__;
	hit_anything = false;
	while (i < world->nmemb)
	{
		current = ft_darray_get_by_index(world, i);
		if (current->hit(&current->shape, r, &t) && (t < hr->t && t > 0.0))
		{
			hit_anything = true;
			hr->t = t;
			hr->r = *r;
			hr->at = ray_at(r, t);
			hr->hit = current;
			hr->normal = get_normal(r, &hr->at, hr->hit);
		}
		i ++;
	}
	return (hit_anything);
}
