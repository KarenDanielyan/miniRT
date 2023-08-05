/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 02:02:36 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/06 02:10:27 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	on_keypress(int key, t_control *ctl)
{
	if (key == ESC)
		on_destroy(ctl);
	return (EXIT_SUCCESS);
}
