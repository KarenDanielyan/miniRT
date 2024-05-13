/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:10:54 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/13 12:49:35 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "defines.h"
# include "miniRT.h"
# include <unistd.h>
# include <fcntl.h>

typedef enum e_parsetypes	t_parsetypes;

enum e_parsetypes
{
	P_CAMERA,
	P_SPHERE,
	P_PLANE,
	P_CYLINDER,
	P_POINTLIGHT,
	P_AMBIENT,
	P_ERRTYPE
};

int		check_extension(char *name);

void	*parse_camera(t_control *ctl, t_list *tokens, int *parse_type);
void	*parse_ambient(t_control *ctl, t_list *tokens, int *parse_type);
void	*parse_light(t_control *ctl, t_list *tokens, int *parse_type);
void	*parse_sphere(t_control *ctl, t_list *tokens, int *parse_type);

#endif