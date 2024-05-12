/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:54:44 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/12 21:01:57 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

void	*new_light(double brightness, t_vec3 position, t_color color)
{
	t_light	*l;

	l = ft_calloc(sizeof(t_light), 1);
	if (l == NULL)
	{
		perror("Error::");
		exit(EXIT_FAILURE);
	}
	l->position = position;
	l->brightness = brightness;
	l->color = color;
	l->type = POINT;
	return (l);
}
