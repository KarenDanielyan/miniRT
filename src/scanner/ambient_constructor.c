/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_constructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:46:30 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/12 16:34:24 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

void	*new_ambient(double brightness, t_color color)
{
	t_light	*l;

	l = ft_calloc(sizeof(t_light), 1);
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
