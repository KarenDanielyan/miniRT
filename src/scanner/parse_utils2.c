/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:03:25 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/21 20:29:41 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

void	init_fields(t_pfields *f)
{
	f->rgb = NULL;
	f->ratio = NULL;
	f->coords = NULL;
	f->height = NULL;
	f->normal = NULL;
	f->radius = NULL;
	f->diameter = NULL;
}

void	free_fields(t_pfields *f)
{
	free_2d(f->rgb);
	free_2d(f->coords);
	free_2d(f->normal);
	free(f->ratio);
	free(f->height);
	free(f->radius);
	free(f->diameter);
}
