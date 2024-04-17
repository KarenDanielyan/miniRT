/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:56:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 20:00:23 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

/* Here we define hittable objects and their structures. */

# include "defines.h"

typedef struct s_hitrecord	t_hitrecord;

typedef struct s_hittable	t_hittable;
typedef union u_shape		t_shape;
typedef enum e_type			t_type;

typedef struct s_sphere		t_sphere;

typedef float				(*t_hit)(t_shape *self, t_ray *r);

enum	e_type
{
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	CUBE,
	NOTASHAPE
};

struct s_sphere
{
	t_point3	center;
	float		radius;
};

union u_shape
{
	/* TODO: Add geometry structures. */
	t_sphere	s;
};

/**
 * @brief This structure contains a record of a ray hitting an object.
 * @details
 * `t` contains data on where the ray hit the object.
 * `obj` is the object we hit.
 */
struct s_hitrecord
{
	float		t;
	t_hittable	*hit;
};

struct s_hittable
{
	t_type	type;
	t_hit	hit;
	t_shape	shape;
};

/* Constructors */

void	*new_hittable(t_type type, t_hit hit, void *shape);

void	*new_sphere(t_point3 center, float radius);

/* Hit functions */

bool	hit_anything(t_ray *r, t_darray *world, t_hitrecord *hr);

float	hit_sphere(t_shape *self, t_ray *r);
float	sphere_hit(t_point3 center, float radius, t_ray *r);


#endif
