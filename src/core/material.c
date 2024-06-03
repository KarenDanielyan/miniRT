/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:45:57 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/03 20:09:44 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "material.h"

static void	set_plastic(t_material *material);
static void	set_mettalic(t_material *material);
static void	set_dielectric(t_material *material);

void	set_material(t_material *material, t_color color, char *type)
{
	material->color = color;
	if (ft_strcmp(type, S_PLASTIC) == 0)
		set_plastic(material);
	else if (ft_strcmp(type, S_METALLIC) == 0)
		set_mettalic(material);
	else if (ft_strcmp(type, S_DIELECTRIC) == 0)
		set_dielectric(material);
	else
	{
		if (ft_strcmp(type, "default") != 0)
			printf("%s%s.%s\n", YELLOW, WARN_INVMATERIAL, RESET);
		material->properties |= DEFAULT;
		material->shininess = 500;
		material->glossiness = 0.0;
	}
}

void	set_texture_and_normal(t_material *m, char *texture, char *normal)
{
	if (texture)
	{
		m->properties |= TEXTURED;
		m->texture_map = load_bmp(texture);
	}
	if (normal)
	{
		m->properties |= NORMAL;
		m->normal_map = load_bmp(normal);
	}
}

static void	set_plastic(t_material *material)
{
	material->properties |= PLASTIC;
	material->glossiness = 0.0;
	material->shininess = 1.0;
}

static void	set_mettalic(t_material *material)
{
	material->properties |= METALIC;
	material->glossiness = 1.0;
	material->shininess = 1.0;
}

static void	set_dielectric(t_material *material)
{
	material->properties |= DIELECRIC;
	material->glossiness = 0.0;
	material->shininess = 1.0;
	material->ri = 1.5;
}
