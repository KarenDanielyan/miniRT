/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:10:54 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/18 21:40:31 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "defines.h"
# include "miniRT.h"
# include <unistd.h>

int		check_extension(char *name);

void	*parse_object(t_control *ctl, char *line);
void	*parse_camera(t_control *ctl, char **splitted_arr);

#endif