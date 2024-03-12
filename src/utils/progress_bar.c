/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:03:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/12 15:52:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

#define BAR_LEN 50

void	print_bar(t_control *ctl, int done)
{
	int	num_chars;
	int	i;

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
