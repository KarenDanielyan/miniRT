/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:38:47 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/16 21:07:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

void	*new_ambient(double brightness, t_color color)
{
	t_light	*l;

	l = ft_calloc(1, sizeof(t_light));
	if (l == NULL)
	{
		perror("Error::");
		exit(EXIT_FAILURE);
	}
	l->brightness = brightness;
	l->color = color;
	l->type = AMBIENT;
	return (l);
}

void	*new_light(double brightness, t_point3 position, t_color color)
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
