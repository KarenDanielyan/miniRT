/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:57:52 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:33:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

/* This is the declaration of vec3 class. */

# include <math.h>
# include "defines.h"

typedef struct s_vec3	t_vec3;

/* Class Fields */
/* WARN: Do not access the fields directrly. Use get/set functions */
struct s_vec3
{
	double	e[3];
};

/* Constructors */
void		new_vec3(t_vec3 *v, double e1, double e2, double e3);
t_vec3		vec3(double e1, double e2, double e3);

/* Properties */
double		get_x(t_vec3 *self);
double		get_y(t_vec3 *self);
double		get_z(t_vec3 *self);

void		set_x(t_vec3 *v, double value);
void		set_y(t_vec3 *v, double value);
void		set_z(t_vec3 *v, double value);

/* Class Methods */
t_vec3		vec3_neg(t_vec3 *self);

void		vec3_sum(t_vec3 *self, t_vec3 *v);
void		vec3_mult(t_vec3 *self, const double t);
void		vec3_div(t_vec3 *self, const double t);
void		vec3_normalize(t_vec3 *self);

double		vec3_length(t_vec3 *self);
double		vec3_length_squared(t_vec3 *self);

double		vec3_dot(const t_vec3 *u, const t_vec3 *v);
t_vec3		vec3_cross(const t_vec3 *u, const t_vec3 *v);
t_vec3		unit_vector(t_vec3 v);

t_vec3		random_vector(void);
t_vec3		random_hemisphere_vector(void);

/* Some utility inline functions */
static inline t_vec3	sum_vec3(t_vec3 *u, t_vec3 *v)
{
	return (vec3(u->e[0] + v->e[0], u->e[1] + v->e[1], u->e[2] + v->e[2]));
}

static inline t_vec3	subst_vec3(t_vec3 *u, t_vec3 *v)
{
	return (vec3(u->e[0] - v->e[0], u->e[1] - v->e[1], u->e[2] - v->e[2]));
}

static inline t_vec3	mult_vec3(t_vec3 *u, t_vec3 *v)
{
	return (vec3(u->e[0] * v->e[0], u->e[1] * v->e[1], u->e[2] * v->e[2]));
}

static inline t_vec3	scale_vec3(float t, t_vec3 *v)
{
	return (vec3(t * v->e[0], t * v->e[1], t * v->e[2]));
}

static inline t_vec3	shrink_vec3(float t, t_vec3 *v)
{
	return (scale_vec3(1 / t, v));
}

#endif