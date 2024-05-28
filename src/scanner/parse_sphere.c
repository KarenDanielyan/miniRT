/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:44:30 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/21 21:13:03 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_pfields *f);
static void			*make(t_pfields *f);

void	*parse_sphere(t_list *tokens, t_parsetype *pt)
{
	t_pfields	f;
	void		*hittable;

	hittable = NULL;
	init_fields(&f);
	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s: %s%d%s", RED, S_LIGHT, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	f.coords = tuple_split(ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	f.rgb = tuple_split(ft_lst_get_by_index(tokens, 3)->content, ',', 3);
	f.diameter = ft_strdup(ft_lst_get_by_index(tokens, 2)->content);
	*pt = argument_check(&f);
	if (*pt == P_OBJECT)
		hittable = make(&f);
	free_fields(&f);
	return (hittable);
}

static void	*make(t_pfields *f)
{
	void	*shape;
	void	*hittable;

	shape = new_sphere(vec3(ft_atof(f->coords[0]), \
						ft_atof(f->coords[1]), \
						ft_atof(f->coords[2])), \
					ft_atof(f->diameter) / 2);
	hittable = new_hittable(SPHERE, &hit_sphere, shape);
	((t_hittable *)hittable)->material.color = vec3(ft_map(ft_atof(f->rgb[0])), \
			ft_map(ft_atof(f->rgb[1])), ft_map(ft_atof(f->rgb[2])));
	free(shape);
	return (hittable);
}

static t_parsetype	argument_check(t_pfields *f)
{
	t_parsetype	rv;

	rv = P_ERROR;
	if (check_number(f->diameter) == EXIT_FAILURE || \
		ft_atof(f->diameter) <= 0.0)
		printf("%s%s: %sdiameter.%s\n", RED, S_SPHERE, ERR_INVALID, RESET);
	else if (!f->coords)
		printf("%s%s: %scoordinates.%s\n", RED, S_SPHERE, ERR_INVALID, RESET);
	else if (!f->rgb || check_color(f->rgb) == EXIT_FAILURE)
		printf("%s%s: %scolor.%s\n", RED, S_SPHERE, ERR_INVALID, RESET);
	else
		rv = P_OBJECT;
	return (rv);
}
