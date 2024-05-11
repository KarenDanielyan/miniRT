/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:43 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 16:31:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "scanner.h"
#include "shapes.h"

static char	scan_prime(t_control *ctl, int fd);
static void	*parse_object(t_control *ctl, char *line, int *parse_type);

char	scan(t_control *ctl, char *filename)
{
	int		fd;

	if (check_extension(filename) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	ft_darray_init(&ctl->world, sizeof(t_hittable), 5);
	ft_darray_init(&ctl->lights, sizeof(t_light), 5);
	return (scan_prime(ctl, fd));
}

static char	scan_prime(t_control *ctl, int fd)
{
	char	*str;
	void	*content;
	int		parse_type;

	str = NULL;
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		content = parse_object(ctl, str, &parse_type);
		free(str);
		if (!content && parse_type == P_ERRTYPE)
		{
			printf(ERROR_MSG);
			return (EXIT_FAILURE);
		}
		if (content && parse_type >= P_SPHERE && parse_type < P_POINTLIGHT)
			ft_darray_pushback(&ctl->world, content);
		else if (content && parse_type >= P_POINTLIGHT && parse_type < P_ERRTYPE)
			ft_darray_pushback(&ctl->lights, content);
		free(content);
	}
	return (EXIT_SUCCESS);
}

static t_list	*get_tokens(char *line)
{
	t_list	*head;
	char	*tmp;

	tmp = NULL;
	head = NULL;
	while (*line)
	{
		while (*line && ft_iswhitespace(*line))
			line++;
		while (*line && !ft_iswhitespace(*line))
			ft_strappend(&tmp, *line++);
		if (tmp)
			ft_lstadd_back(&head, ft_lstnew(tmp));
		tmp = NULL;
	}
	return (head);
}

/* TODO: Add comment feature (Usage: # Here is your comment. )*/
static void	*parse_object(t_control *ctl, char *line, int *parse_type)
{
	void		*rv;
	t_list		*tokens;

	(void)ctl;
	rv = NULL;
	tokens = get_tokens(line);
	if (!ft_strcmp((char *)(tokens->content), "C"))
		rv = parse_camera(ctl, tokens, parse_type);
	else if (!ft_strcmp((char *)(tokens->content), "A"))
		rv = parse_ambient(ctl, tokens, parse_type);
	else if (!ft_strcmp((char *)(tokens->content), "L"))
		rv = NULL;
	else if (!ft_strcmp((char *)(tokens->content), "sp"))
		rv = NULL;
	else
		printf("%s%s%s", RED, ERR_BADARG, RESET);
	ft_lstclear(&tokens, &free);
	return (rv);
}
