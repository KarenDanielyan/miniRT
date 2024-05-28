/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:45:57 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/28 18:31:46 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "material.h"

void	set_material(t_material *material, t_color color, char *type)
{
	material->color = color;
	if (ft_strcmp(type, S_PLASTIC) == 0)
	{
	}
	else if (ft_strcmp(type, S_METALLIC) == 0)
	{
	}
	else if (ft_strcmp(type, S_DIELECTRIC) == 0)
	{
	}
	else
	{
		if (ft_strcmp(type, "default") != 0)
			printf("%s%s.%s\n", YELLOW, WARN_INVMATERIAL, RESET);
		material->properties |= DEFAULT;
	}
}

void	set_texture(t_material *material, char *texture_map)
{
	(void)material;
	(void)texture_map;
}

void	set_normal_map(t_material *material, char *normal_map)
{
	(void)material;
	(void)normal_map;
}
