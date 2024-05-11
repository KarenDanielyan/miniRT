/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:43 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 15:26:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "scanner.h"
#include "shapes.h"

static void	scan_prime(t_control *ctl, int fd);
static void	*parse_object(t_control *ctl, char *line);

char	scan(t_control *ctl, char *filename)
{
	int	fd;

	if (check_extension(filename) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	scan_prime(ctl, fd);
	return (EXIT_SUCCESS);
}

static void	scan_prime(t_control *ctl, int fd)
{
	char	*str;
	void	*content;

	str = NULL;
	ft_darray_init(&ctl->world, sizeof(t_hittable), 5);
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		content = parse_object(ctl, str);
		if (!content && str[0] != 'C')
		{
			printf(ERROR_MSG);
			free(str);
			break ;
		}
		if (content)
			ft_darray_pushback(&ctl->world, content);
		free(content);
		free(str);
	}
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
static void	*parse_object(t_control *ctl, char *line)
{
	void		*rv;
	t_list		*tokens;

	(void)ctl;
	rv = NULL;
	tokens = get_tokens(line);
	if (!ft_strcmp((char *)(tokens->content), "C"))
		rv = parse_camera(ctl, tokens);
	else if (!ft_strcmp((char *)(tokens->content), "A"))
		rv = NULL;
	else if (!ft_strcmp((char *)(tokens->content), "sp"))
		rv = NULL;
	else if (!ft_strcmp((char *)(tokens->content), "L"))
		rv = NULL;
	else
		printf("%s%s%s", RED, ERR_BADARG, RESET);
	ft_lstclear(&tokens, &free);
	return (rv);
}
