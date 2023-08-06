/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:28:29 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/06 14:46:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "defines.h"

void	create_image(char *name, int *pixels, int w, int h);
void	new_image(void *mlx_ptr, int width, int height, t_image *image);

/* Floating point operations */
bool	float_equal(float a, float b);

#endif