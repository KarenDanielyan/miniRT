/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:26:09 by armhakob          #+#    #+#             */
/*   Updated: 2024/06/13 03:28:41 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_pfields *f);
static void			*make(t_pfields *f);

void	*parse_cyliner(t_list *tokens, t_parsetype *pt)
{
	void		*hittable;
	size_t		size;
	t_pfields	f;

	hittable = NULL;
	init_fields(&f);
	size = ft_lstsize(tokens);
	if (size < 6 || size > 7)
	{
		printf("%s%s: %s%d%s", RED, S_CYLINDER, ERR_INVALID_ARGS, 5, RESET);
		*pt = P_ERROR;
		return (hittable);
	}
	f.coords = tuple_split(ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	f.normal = tuple_split(ft_lst_get_by_index(tokens, 2)->content, ',', 3);
	f.diameter = ft_strdup(ft_lst_get_by_index(tokens, 3)->content);
	f.height = ft_strdup(ft_lst_get_by_index(tokens, 4)->content);
	f.rgb = tuple_split(ft_lst_get_by_index(tokens, 5)->content, ',', 3);
	*pt = argument_check(&f);
	*pt = optional_check(ft_lst_get_by_index(tokens, 6), &f, CYLINDER);
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
		printf("%s%s: %s coordinates.%s\n", \
			RED, S_CYLINDER, ERR_INVALID, RESET);
	else if (!f->normal)
		printf("%s%s: %s normal vector.%s\n", \
		RED, S_CYLINDER, ERR_INVALID, RESET);
	else if (!f->rgb || check_color(f->rgb) == EXIT_FAILURE)
		printf("%s%s: %s color.%s\n", RED, S_CYLINDER, ERR_INVALID, RESET);
	else if (check_number(f->diameter) == EXIT_FAILURE || \
		ft_atof(f->diameter) < 0.0)
		printf("%s%s: %s diameter.%s\n", RED, S_CYLINDER, ERR_INVALID, RESET);
	else if (check_number(f->height) == EXIT_FAILURE || \
		ft_atof(f->height) < 0.0)
		printf("%s%s: %s height.%s\n", RED, S_CYLINDER, ERR_INVALID, RESET);
	else
		rv = P_OBJECT;
	return (rv);
}

static void	*make(t_pfields *f)
{
	void	*cylinder;
	void	*hittable;

	check_for_warnings(f, S_CYLINDER);
	cylinder = new_cylinder(vec3(ft_atof(f->coords[0]), \
							ft_atof(f->coords[1]), ft_atof(f->coords[2])), \
							unit_vector(vec3(ft_atof(f->normal[0]), \
							ft_atof(f->normal[1]), ft_atof(f->normal[2]))), \
				ft_atof(f->diameter) / 2, ft_atof(f->height));
	hittable = new_hittable(CYLINDER, &hit_cylinder, cylinder);
	set_material(&((t_hittable *)hittable)->material, \
				vec3(ft_map(ft_atof(f->rgb[0])), \
					ft_map(ft_atof(f->rgb[1])), \
					ft_map(ft_atof(f->rgb[2]))), (f->material + 2));
	set_texture_and_normal(&((t_hittable *)hittable)->material, f->texture, \
							f->normal_map);
	free(cylinder);
	return (hittable);
}
