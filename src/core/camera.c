/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:40:17 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/25 17:02:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "camera.h"

void	initialize_camera(t_camera *cam)
{
	double	aspect_ratio;

	aspect_ratio = IMAGE_WIDTH / IMAGE_HEIGHT;
	cam->focal_length = FOCAL_LENGTH / 100;
	(void)aspect_ratio;
}
