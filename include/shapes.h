/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:56:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/15 19:54:15 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

/* Here we define hittable objects and their structures. */

# include "defines.h"

typedef struct s_hittable	t_hittable;
typedef union u_shape		t_shape;
typedef enum e_type			t_type;

typedef struct s_sphere		t_sphere;

enum	e_type
{
	PLANE,
	SPHERE
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

struct s_hittable
{
	t_type	type;
	t_hit	hit;
	t_shape	shape;
};

/* Hit functions */

float	hit_sphere(t_sphere *self, t_ray *r);
float	sphere_hit(t_point3 center, float radius, t_ray *r);

#endif