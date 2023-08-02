/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:43:07 by kdaniely          #+#    #+#             */
/*   Updated: 2023/05/27 16:43:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static void	free_feed(char *line_feed[OPEN_MAX])
{
	unsigned short	i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (line_feed[i])
			free(line_feed[i]);
		i++;
	}
}

static char	*feed(int fd, char *line_feed)
{
	char	buf[BUFFER_SIZE + 1];
	char	*join;
	long	r_size;

	while (1)
	{
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size < 0)
		{
			free(line_feed);
			return (NULL);
		}
		buf[r_size] = '\0';
		if (!line_feed)
			join = gnl_strdup(buf);
		else
			join = gnl_strjoin (line_feed, buf);
		line_feed = join;
		if (gnl_strchr(line_feed, '\n') || r_size == 0)
			break ;
	}
	return (line_feed);
}

char	*get_next_line(int fd)
{
	static char		*line_feed[OPEN_MAX];
	char			*to_free;
	char			*str;
	size_t			len;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (fd == -42)
	{
		free_feed(line_feed);
		return (NULL);
	}
	line_feed[fd] = feed(fd, line_feed[fd]);
	if (!line_feed[fd])
		return (NULL);
	len = gnl_strchr(line_feed[fd], '\n') - line_feed[fd];
	str = gnl_substr(line_feed[fd], 0, len + 1);
	to_free = line_feed[fd];
	line_feed[fd] = gnl_substr(line_feed[fd], len + 1,
			(gnl_strlen(line_feed[fd]) - len));
	free(to_free);
	return (str);
}
