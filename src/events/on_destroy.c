/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:51:14 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/06 02:05:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <mlx.h>

int	on_destroy(t_control *ctl)
{
	mlx_destroy_window(ctl->mlx_ptr, ctl->win_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
