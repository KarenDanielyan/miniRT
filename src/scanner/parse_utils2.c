/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:03:25 by armhakob          #+#    #+#             */
/*   Updated: 2024/06/13 18:44:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static bool	check_texture_and_normal(t_list *tokens, t_pfields *f);
static bool	check_material(t_list *tokens, t_pfields *f);

void	init_fields(t_pfields *f)
{
	f->rgb = NULL;
	f->ratio = NULL;
	f->coords = NULL;
	f->height = NULL;
	f->normal = NULL;
	f->radius = NULL;
	f->diameter = NULL;
	f->material = NULL;
	f->texture = NULL;
	f->normal_map = NULL;
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
	free(f->material);
	free(f->texture);
	free(f->normal_map);
}

t_parsetype	optional_check(t_list *tokens, t_pfields *f, t_type type)
{
	while (tokens)
	{
		if (check_material(tokens, f) == EXIT_FAILURE)
			return (P_ERROR);
		if (check_texture_and_normal(tokens, f) == EXIT_FAILURE)
			return (P_ERROR);
		if (type != PLANE && type != SPHERE && (f->texture || f->normal_map))
		{
			printf("%sError: %s%s\n", RED, ERR_TXTNSUPPORTED, RESET);
			return (P_ERROR);
		}
		tokens = tokens->next;
	}
	return (P_OBJECT);
}

static bool	check_texture_and_normal(t_list *tokens, t_pfields *f)
{
	if (!ft_strncmp(tokens->content, "t:", 2))
	{
		f->texture = ft_strdup(tokens->content + 2);
		if (ft_strcmp(f->texture, "checker") != 0 && \
			(check_extension(f->texture, ".bmp") == EXIT_FAILURE || \
			access(f->texture, F_OK) == -1))
		{
			if (access(f->texture, F_OK) == -1)
				printf("%sError: %s.%s\n", RED, strerror(ENOENT), RESET);
			return (EXIT_FAILURE);
		}
	}
	else if (!ft_strncmp(tokens->content, "n:", 2))
	{
		f->normal_map = ft_strdup(tokens->content + 2);
		if (check_extension(f->normal_map, ".bmp") == EXIT_FAILURE || \
			access(f->normal_map, F_OK) == -1)
		{
			if (access(f->normal_map, F_OK) == -1)
				printf("%sError: %s.%s\n", RED, strerror(ENOENT), RESET);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static bool	check_material(t_list *tokens, t_pfields *f)
{
	if (!ft_strncmp(tokens->content, "m:", 2))
	{
		if (f->material)
		{
			free(f->material);
			printf("%s%s%s\n", YELLOW, WARN_MANYMATERIAL, RESET);
		}
		f->material = ft_strdup(tokens->content);
	}
	return (EXIT_SUCCESS);
}
