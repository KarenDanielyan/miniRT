/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:03:32 by kdaniely          #+#    #+#             */
/*   Updated: 2023/09/01 21:09:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

#ifdef __APPLE__

# define BAR_LEN 50

void	print_bar(t_control *ctl, int done)
{
	int			num_chars;
	int			i;

	i = -1;
	(void)ctl;
	num_chars = (done * BAR_LEN) / 100;
	printf("\r%3d%%[", done);
	while (++i < num_chars)
		printf("\033[32m▦\033[0m");
	i = -1;
	while (++i < (BAR_LEN - num_chars))
		printf(" ");
	printf("]");
	fflush(stdout);
}
#elif __linux__

# define BAR_LEN 20

void	print_bar(t_control *ctl, int done)
{
	static char	*prev;
	char		*str;
	int			num_chars;
	int			i;

	i = -1;
	num_chars = (done * BAR_LEN) / 100;
	str = ft_itoa(done);
	str = ft_strjoin_free(str, "%[");
	while (++i < num_chars)
		ft_strappend(&str, '#');
	i = -1;
	while (++i < (BAR_LEN - num_chars))
		ft_strappend(&str, ' ');
	ft_strappend(&str, ']');
	if (prev)
		mlx_string_put(ctl->mlx_ptr, ctl->win_ptr, \
			ctl->ui.info_shift_u, ctl->ui.info_shift_v, INFO_C, prev);
	mlx_string_put(ctl->mlx_ptr, ctl->win_ptr, \
			ctl->ui.info_shift_u, ctl->ui.info_shift_v, STATUS_C, str);
	free(prev);
	prev = str;
}
#endif
