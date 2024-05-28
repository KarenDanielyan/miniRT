/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:44:16 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/21 21:11:28 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_pfields *f);
void				*make(t_pfields *f);

/* Light: position -> brightness -> color */
void	*parse_light(t_list *tokens, t_parsetype *pt)
{
	void		*rv;
	t_pfields	f;

	rv = NULL;
	init_fields(&f);
	*pt = P_ERROR;
	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s: %s%d%s", RED, S_LIGHT, ERR_INVALID_ARGS, 4, RESET);
		return (NULL);
	}
	f.coords = tuple_split(ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	f.rgb = tuple_split(ft_lst_get_by_index(tokens, 3)->content, ',', 3);
	f.ratio = ft_strdup(ft_lst_get_by_index(tokens, 2)->content);
	*pt = argument_check(&f);
	if (*pt == P_LIGHTSOURCE)
		rv = make(&f);
	free_fields(&f);
	return (rv);
}

void	*make(t_pfields *f)
{
	return (new_light(ft_atof(f->ratio), \
				vec3(ft_atof(f->coords[0]), ft_atof(f->coords[1]), \
					ft_atof(f->coords[2])), \
					vec3(ft_map(ft_atof(f->rgb[0])), \
					ft_map(ft_atof(f->rgb[1])), \
					ft_map(ft_atof(f->rgb[2])))));
}

static t_parsetype	argument_check(t_pfields *f)
{
	t_parsetype	rv;

	rv = P_ERROR;
	if (check_number(f->ratio) == EXIT_FAILURE || \
		ft_atof(f->ratio) < 0.0 || ft_atof(f->ratio) > 1.0)
		printf("%s%s: %scoordinates.%s\n", RED, S_LIGHT, ERR_INVALID, RESET);
	else if (!f->coords)
		printf("%s%s: %scoordinates.%s\n", RED, S_LIGHT, ERR_INVALID, RESET);
	else if (!f->rgb || check_color(f->rgb) == EXIT_FAILURE)
		printf("%s%s: %scolor.%s\n", RED, S_LIGHT, ERR_INVALID, RESET);
	else
		rv = P_LIGHTSOURCE;
	return (rv);
}
