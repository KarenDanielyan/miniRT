/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:26:03 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/28 18:31:46 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_pfields *f);
static void			*make(t_pfields *f);

void	*parse_plane(t_list *tokens, t_parsetype *pt)
{
	void		*hittable;
	size_t		size;
	t_pfields	f;

	hittable = NULL;
	init_fields(&f);
	size = ft_lstsize(tokens);
	if (size < 4 || size > 5)
	{
		printf("%s%s: %s%d%s", RED, S_PLANE, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	f.rgb = tuple_split(\
		ft_lst_get_by_index(tokens, 3)->content, ',', 3);
	f.normal = tuple_split(\
		ft_lst_get_by_index(tokens, 2)->content, ',', 3);
	f.coords = tuple_split(\
		ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	*pt = argument_check(&f);
	*pt = optional_check(ft_lst_get_by_index(tokens, 4), &f);
	if (*pt == P_OBJECT)
		hittable = make(&f);
	free_fields(&f);
	return (hittable);
}

static t_parsetype	argument_check(t_pfields *f)
{
	t_parsetype	rv;

	rv = P_ERROR;
	if (!f->coords)
		printf("%s%s: %s coordinates.%s\n", RED, S_PLANE, ERR_INVALID, RESET);
	else if (!f->normal)
		printf("%s%s: %s normal vector.%s\n", RED, S_PLANE, ERR_INVALID, RESET);
	else if (!f->rgb || check_color(f->rgb) == EXIT_FAILURE)
		printf("%s%s: %s color.%s\n", RED, S_PLANE, ERR_INVALID, RESET);
	else
		rv = P_OBJECT;
	return (rv);
}

static void	*make(t_pfields *f)
{
	void	*plane;
	void	*hittable;

	plane = new_plane(vec3(ft_atof(f->coords[0]), ft_atof(f->coords[1]), \
							ft_atof(f->coords[2])), \
					vec3(ft_atof(f->normal[0]), ft_atof(f->normal[1]), \
							ft_atof(f->normal[2])));
	hittable = new_hittable(PLANE, &hit_plane, plane);
	if (!f->material)
	{
		printf("%s%s: %s.%s\n", YELLOW, S_PLANE, WARN_NOMATERIAL, RESET);
		f->material = ft_strdup("m:default");
	}
	set_material(&((t_hittable *)hittable)->material, \
				vec3(ft_map(ft_atof(f->rgb[0])), \
					ft_map(ft_atof(f->rgb[1])), \
					ft_map(ft_atof(f->rgb[2]))), (f->material + 2));
	if (f->texture)
		set_texture(&((t_hittable *)hittable)->material, f->texture);
	if (f->normal_map)
		set_normal_map(&((t_hittable *)hittable)->material, f->normal_map);
	free(plane);
	return (hittable);
}
