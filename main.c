/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:32:25 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/07 18:18:29 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <fcntl.h>

# define SAMPLES_NUM 100000

int	main(void)
{
	int		numbrer_of_samples = SAMPLES_NUM;
	int		fd = open("./random.csv", O_CREAT | O_TRUNC | O_RDWR);

	dprintf(fd, "Index,Value\n");
	while (numbrer_of_samples --)
	{
		dprintf(fd, "%d, %f, %f, %f\n", \
			(SAMPLES_NUM - numbrer_of_samples), \
			ft_random_gaussian_value(), \
			ft_random_gaussian_value(), \
			ft_random_gaussian_value());
	}
	close(fd);
	return (EXIT_SUCCESS);
}