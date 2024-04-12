/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:17:47 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/10 21:30:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4_H
# define MATRIX4_H

# include "defines.h"

void	matrix44_new(t_matrix4	*self);

void	matvec_mult(t_matrix4 *m, t_vec3 *vec, t_vec3 *result);

void	apply_rotation(t_matrix4 *m, t_vec3 *vec, t_vec3 *result);

#endif