/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:10:54 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/21 20:08:10 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "defines.h"
# include "miniRT.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_parsefields	t_pfields;
typedef enum e_parsetype		t_parsetype;

enum e_parsetype
{
	P_CAMERA,
	P_LIGHTSOURCE,
	P_OBJECT,
	P_COMMENT,
	P_ERROR
};

struct s_parsefields
{
	char	**rgb;
	char	**coords;
	char	**normal;
	char	*diameter;
	char	*radius;
	char	*height;
};

int		check_extension(char *name);

void	*parse_camera(t_control *ctl, t_list *tokens, t_parsetype *pt);

void	*parse_rectangle(t_list *tokens, t_parsetype *pt);
void	*parse_cyliner(t_list *tokens, t_parsetype *pt);
void	*parse_ambient(t_list *tokens, t_parsetype *pt);
void	*parse_sphere(t_list *tokens, t_parsetype *pt);
void	*parse_light(t_list *tokens, t_parsetype *pt);
void	*parse_plane(t_list *tokens, t_parsetype *pt);
void	*parse_cone(t_list *tokens, t_parsetype *pt);

/* Utility Functions */

bool	check_number(char *number);
bool	check_tuple(char *tuple, int size);
bool	check_color(char **rgb);

char	**tuple_split(char *tuple, char c, int size);

void	init_fields(t_pfields *f);
void	free_fields(t_pfields *f);

#endif