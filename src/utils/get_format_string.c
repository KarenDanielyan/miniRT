/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:57:25 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/28 16:38:37 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>

char	*get_format_string(char *str, va_list args)
{
	char	*formatted;
	char	*tmp;
	int		fd[2];

	formatted = NULL;
	if (pipe(fd) < 0)
	{
		perror("pipe()");
		exit(EXIT_FAILURE);
	}
	ft_vdprintf(fd[1], str, args);
	close(fd[1]);
	while (1)
	{
		tmp = get_next_line(fd[0]);
		if (!tmp)
			break ;
		formatted = ft_strjoin_free(formatted, tmp);
		free(tmp);
	}
	close(fd[0]);
	if (formatted == NULL && str != NULL)
		formatted = ft_strdup("");
	return (formatted);
}
