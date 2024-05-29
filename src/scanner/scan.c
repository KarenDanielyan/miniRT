/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:43 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/29 13:12:20 by armhakob         ###   ########.fr       */
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

	if (check_extension(filename, EXTENSION) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	ft_darray_init(&ctl->world, sizeof(t_hittable), 5);
	ft_darray_init(&ctl->lights, sizeof(t_light), 5);
	rv = scan_prime(ctl, fd);
	if (ft_darray_get_if(&ctl->lights, is_ambient) == NULL)
	{
		printf("%s%s: %s 1.%s\n", RED, S_AMBIENT, ERR_INVALID_ARGS, RESET);
		return (EXIT_FAILURE);
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
		content = parse_object(ctl, tokens, &pt);
		free(str);
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
		printf("%s%s%s", RED, ERR_BADARG, RESET);
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
		printf("%s%s: %s.%s\n", RED, S_AMBIENT, ERR_ARGNUM, RESET);
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
 * 
 * @param line		The line.
 * @return t_list*	Linked list of tokens.
 */
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
