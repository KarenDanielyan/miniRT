/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_to_gamma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:32:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/18 17:13:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	linear_to_gamma(t_color l)
{
	double	tmp;
	t_color	c;

	set_x(&c, 0.0);
	set_y(&c, 0.0);
	set_z(&c, 0.0);
	tmp = get_x(&l);
	if (tmp > 0.0)
		set_x(&c, sqrt(tmp));
	tmp = get_y(&l);
	if (tmp > 0.0)
		set_y(&c, sqrt(tmp));
	tmp = get_z(&l);
	if (tmp > 0.0)
		set_z(&c, sqrt(tmp));
	return (c);
}
