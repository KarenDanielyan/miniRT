/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:44:49 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/28 17:57:31 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "defines.h"
# include "vec3.h"

typedef struct s_vec3		t_color;
typedef struct s_bitmap		t_bitmap;
typedef struct s_material	t_material;
typedef enum e_mtype		t_mtype;

static inline void	set_color(int *pixel, t_color color)
{
	*pixel = (int)(get_x(&color) * 255.999) << 16 \
		| (int)(get_y(&color) * 255.999) << 8 \
		| (int)(get_z(&color) * 255.999);
}

enum e_mtype
{
	DEFAULT = 0,
	PLASTIC = 1,
	METALIC = 2,
	DIELECRIC = 4
};

struct s_material
{
	int		properties;
	double	lambertian;
	double	specular;
	double	glossiness;
	double	refractive_index;
	void	*normal_map;
	void	*texture_map;
	t_color	color;
};

void	set_material(t_material *material, t_color color, char *type);
void	set_texture(t_material *material, char *texture_map);
void	set_normal_map(t_material *material, char *normal_map);

/* Working with bitmaps */

struct s_bitmap
{
};

void	*load_bmp(char *path);
void	save_bmp(char *path, void *bitmap);

#endif
