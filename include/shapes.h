/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:56:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 21:22:54 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "defines.h"

/* Here we define hittable objects and their structures. */

typedef struct s_hittable	t_hittable;
typedef union u_shape		t_shape;
typedef enum e_type			t_type;

enum	e_type
{
	PLANE,
	SPHERE
};

union u_shape
{
	/* TODO: Add geometry structures. */
};

struct s_hittable
{
	t_type	type;
	t_hit	hit_function;
	t_shape	shape;
};

#endif