/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:56:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 18:50:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

/* Here we define hittable objects and their structures. */

# include "defines.h"
# include "ray.h"

typedef struct s_hitrecord	t_hitrecord;

typedef struct s_hittable	t_hittable;
typedef union u_shape		t_shape;
typedef enum e_type			t_type;

typedef struct s_sphere		t_sphere;

typedef bool				(*t_hit)(t_shape *self, t_ray *r, double *t);

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
	double		t;
	t_ray		r;
	t_point3	at;
	t_vec3		normal;
	t_hittable	*hit;
};

struct s_hittable
{
	t_type		type;
	t_hit		hit;
	t_shape		shape;
	t_material	material;
};

/* Constructors */

void	*new_hittable(t_type type, t_hit hit, void *shape);

void	*new_sphere(t_point3 center, float radius);

/* Hit functions */

bool	hit_anything(t_ray *r, t_darray *world, t_hitrecord *hr);

bool	hit_sphere(t_shape *self, t_ray *r, double *t);

/* Surfece Normals */

t_vec3	get_normal(t_ray *r, t_point3 *at, t_hittable *hit);

#endif
