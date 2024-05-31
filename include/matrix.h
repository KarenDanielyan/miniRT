/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:31:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/31 18:35:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "defines.h"
# include "vec3.h"

/**
 * @brief	Structure representing a 4x4 matrix.
 * 			Used for transformations.
 * 			Stored in column-major order.
 * 
 */
typedef struct s_matrix
{
	float	e[4][4];
}	t_matrix;

/**
 * @brief	matrix_identity() - Generates an identity matrix.
 * 
 * @return t_matrix	The identity matrix.
 */
t_matrix	matrix_identity(void);

/**
 * @brief	world_to_local() - Generates a transformation matrix from
 * 			world space to local space using center of the object and the
 * 			direction the object is facing.
 * 
 * @param origin			The origin point of the local coordinate system.
 * @param face_direction	The direction the object is facing.
 * @return t_matrix			The transformation matrix.
 */
t_matrix	world_to_local(t_point3 *origin, t_vec3 *face_direction);

/**
 * @brief	apply_transform_to_vector() - 
 * 			Applies a transformation matrix to a vector.
 * 
 * @param m	The transformation matrix.
 * @param v	The vector to transform.
 * @return t_vec3	The transformed vector.
 */
t_vec3		apply_transform_to_vector(t_matrix *m, t_vec3 *v);

/**
 * @brief	apply_transform_to_point() - 
 * 			Applies a transformation matrix to a point.
 * 
 * @param m	The transformation matrix.
 * @param p	The point to transform.
 * @return t_vec3	The transformed point.
 */
t_point3	apply_transform_to_point(t_matrix *m, t_point3 *p);

#endif
