/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:18 by armhakob          #+#    #+#             */
/*   Updated: 2024/04/18 21:20:44 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str)
{
	float	res;
	float	res2;
	int		len;

	res = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	res2 = (float)ft_atoi(str);
	len = ft_strlen(str);
	while (len--)
		res2 /= 10;
	if (res >= 10)
		return (res + res2);
	else
		return (res + -res2);
}
