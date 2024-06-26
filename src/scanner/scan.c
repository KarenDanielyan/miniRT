/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:43 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/13 21:17:38 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "scanner.h"
#include "shapes.h"

static t_list	*get_tokens(char *line);
static bool		scan_prime(t_control *ctl, int fd);
static bool		check_repition(t_control *ctl, t_list *tokens, t_parsetype *pt);
static void		*parse_object(t_control *ctl, t_list *tokens, t_parsetype *pt);

/**
 * @brief	scan() checks the validity of the input file,
 * 			and read's the contents inside to create the world.
 * 			It will propmt error messages when encounters an error
 * 			in the file.
 * 
 * @param ctl		The control structure of our program.
 * @param filename	Name of the input file.
 * @return bool		Exit code of the program. (EXIT_SUCCESS | EXIT_FAILURE).
 */
bool	scan(t_control *ctl, char *filename)
{
	int		fd;
	bool	rv;

	fd = check_file(filename, EXTENSION);
	if (fd == -1)
		return (EXIT_FAILURE);
	ft_darray_init(&ctl->world, sizeof(t_hittable), 5);
	ft_darray_init(&ctl->lights, sizeof(t_light), 5);
	rv = EXIT_FAILURE;
	if (scan_prime(ctl, fd) == EXIT_SUCCESS)
	{
		if (ft_darray_get_if(&ctl->lights, is_ambient) == NULL)
			printf("%sError: %s is not specified%s\n", RED, S_AMBIENT, RESET);
		else if (ctl->cam.is_active == 0)
			printf("%sError: %s is not specified%s\n", RED, S_CAMERA, RESET);
		else
			rv = EXIT_SUCCESS;
	}
	return (rv);
}

/**
 * @brief		scan_prime() reads the file line by line,
 * 				and parses the object specified in the line.
 * 
 * @param ctl	The control structure of the file.
 * @param fd	file descriptor of the file. (Read Unix manual)
 * @return bool	Returns (EXIT_SUCCESS | EXIT_FAILURE) to indicate
 * 				whether the parsing was successfull or not.
 * 
 * NOTE:		Error messages are printed by appropriate functions
 * 				that parse the object from the line.
 */
static bool	scan_prime(t_control *ctl, int fd)
{
	char		*str;
	void		*content;
	t_list		*tokens;
	t_parsetype	pt;

	str = NULL;
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tokens = get_tokens(str);
		if (!tokens)
			continue ;
		content = parse_object(ctl, tokens, &pt);
		ft_lstclear(&tokens, &free);
		if (pt == P_ERROR)
			return (EXIT_FAILURE);
		else if (pt == P_OBJECT)
			ft_darray_pushback(&ctl->world, content);
		else if (pt == P_LIGHTSOURCE)
			ft_darray_pushback(&ctl->lights, content);
		free(content);
	}
	return (EXIT_SUCCESS);
}

/* TODO: Add comment feature (Usage: # Here is your comment. )*/
static void	*parse_object(t_control *ctl, t_list *tokens, t_parsetype *pt)
{
	if (check_repition(ctl, tokens, pt) == EXIT_FAILURE)
		return (NULL);
	if (!ft_strcmp((char *)(tokens->content), S_CAMERA))
		return (parse_camera(ctl, tokens, pt));
	else if (!ft_strcmp((char *)(tokens->content), S_AMBIENT))
		return (parse_ambient(tokens, pt));
	else if (!ft_strcmp((char *)(tokens->content), S_LIGHT))
		return (parse_light(tokens, pt));
	else if (!ft_strcmp((char *)(tokens->content), S_SPHERE))
		return (parse_sphere(tokens, pt));
	else if (!ft_strcmp((char *)(tokens->content), S_CYLINDER))
		return (parse_cyliner(tokens, pt));
	else if (!ft_strcmp((char *)(tokens->content), S_PLANE))
		return (parse_plane(tokens, pt));
	else if (!ft_strcmp((char *)(tokens->content), S_CONE))
		return (parse_cone(tokens, pt));
	else if (!ft_strncmp((char *)(tokens->content), "#", 1))
		*pt = P_COMMENT;
	else
	{
		printf("%s%s%s\n", RED, ERR_BADARG, RESET);
		*pt = P_ERROR;
	}
	return (NULL);
}

/* Not more than one camera or ambient. */
/* Camera: check if we initialized camera before. */
/* Ambient: same as camera. */
static bool	check_repition(t_control *ctl, t_list *tokens, t_parsetype *pt)
{
	if (!ft_strcmp(tokens->content, S_AMBIENT) && \
		ft_darray_get_if(&ctl->lights, is_ambient) != NULL)
	{
		*pt = P_ERROR;
		printf("%s%s: %s%s", RED, S_AMBIENT, ERR_ARGNUM, RESET);
	}
	else if (!ft_strcmp(tokens->content, S_CAMERA) && \
		ctl->cam.is_active == 1)
	{
		*pt = P_ERROR;
		printf("%s%s: %s.%s\n", RED, S_CAMERA, ERR_ARGNUM, RESET);
	}
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/**
 * @brief			get_tokens() returns a linked list of tokens
 * 					parsed from the line.
 * 					NOTE: The line is freed inside the function,
 * 					so you should not free it again.
 * 
 * @param line		The line.
 * @return t_list*	Linked list of tokens.
 */
static t_list	*get_tokens(char *line)
{
	t_list	*head;
	char	*l;
	char	*tmp;

	tmp = NULL;
	head = NULL;
	l = line;
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
	free(l);
	return (head);
}
