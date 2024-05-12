/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:54:44 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/12 20:32:17 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

void	*new_light(t_vec3 position, double brigthness, t_color color)
{
	t_light	*l;
	
	l = ft_calloc(1, sizeof(t_light));
	if (l == NULL)
	{
		perror("Error::");
		exit(EXIT_FAILURE);
	}
	l->position = position;
	l->brightness = brigthness;
	l->color = color;
	l->type = AMBIENT;
	return (l);
}
