/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:42:47 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/21 21:09:10 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_pfields *f);

/**
	ambient: 1. Symbol -> A, Brightness -> double, RGB -> "x,y,z"

	Pipeline:	1. Check if number of arguments is correct.
				2. Check if arguments are valid.
				3. Create the object using the arguments.
*/
void	*parse_ambient(t_list *tokens, t_parsetype *pt)
{
	void		*rv;
	t_pfields	f;

	rv = NULL;
	init_fields(&f);
	if (ft_lstsize(tokens) != 3)
	{
		printf("%s%s%s%s%d.%s\n", RED, \
			S_AMBIENT, ERR_INVALID_ARGS, " ", 3, RESET);
		*pt = P_ERROR;
		return (rv);
	}
	f.rgb = tuple_split(ft_lst_get_by_index(tokens, 2)->content, ',', 3);
	f.ratio = ft_strdup(ft_lst_get_by_index(tokens, 1)->content);
	*pt = argument_check(&f);
	if (*pt == P_LIGHTSOURCE)
	{
		rv = new_ambient(ft_atof(f.ratio), \
						vec3(ft_map(ft_atof(f.rgb[0])), \
							ft_map(ft_atof(f.rgb[1])), \
							ft_map(ft_atof(f.rgb[2]))));
	}
	free_fields(&f);
	return (rv);
}

static t_parsetype	argument_check(t_pfields *f)
{
	t_parsetype	rv;

	rv = P_ERROR;
	if (check_number(f->ratio) == EXIT_FAILURE || \
		ft_atof(f->ratio) < 0.0 || ft_atof(f->ratio) > 1.0)
		printf("%s%s%sbrightness.%s\n", RED, S_AMBIENT, ERR_INVALID, RESET);
	if (!f->rgb || check_color(f->rgb) == EXIT_FAILURE)
		printf("%s%s%sbrightness.%s\n", RED, S_AMBIENT, ERR_INVALID, RESET);
	else
		rv = P_LIGHTSOURCE;
	return (rv);
}
