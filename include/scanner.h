/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:10:54 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 15:26:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "defines.h"
# include "miniRT.h"
# include <unistd.h>
# include <fcntl.h>

int		check_extension(char *name);

void	*parse_camera(t_control *ctl, t_list *tokens);

#endif