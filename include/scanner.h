/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:10:54 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/18 19:01:30 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "defines.h"
# include "miniRT.h"
# include <unistd.h>
# include <fcntl.h>

typedef enum e_parsetype	t_parsetype;

enum e_parsetype
{
	P_CAMERA,
	P_LIGHTSOURCE,
	P_OBJECT,
	P_COMMENT,
	P_ERROR
};

int		check_extension(char *name);

void	*parse_camera(t_control *ctl, t_list *tokens, t_parsetype *pt);

void	*parse_ambient(t_list *tokens, t_parsetype *pt);
void	*parse_light(t_list *tokens, t_parsetype *pt);
void	*parse_sphere(t_list *tokens, t_parsetype *pt);

bool	check_number(char *number);
bool	check_tuple(char *tuple, int size);
char	**tuple_split(char *tuple, char c,int size);
#endif