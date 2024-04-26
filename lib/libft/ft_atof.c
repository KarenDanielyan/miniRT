/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:18 by armhakob          #+#    #+#             */
/*   Updated: 2024/04/18 22:30:44 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	is_whitespace(const char *chr);

float	ft_atof(char *str)
{
	float	res;
	float	res2;
	int		len;
	short	sign;

	sign = 1;
	while (is_whitespace(str))
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str ++;
	}
	res = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	res2 = (float)ft_atoi(str);
	len = ft_strlen(str);
	while (len--)
		res2 /= 10;
	return ((res + res2) * sign);
}

static short	is_whitespace(const char *chr)
{
	if ((*chr >= '\b' && *chr <= '\r') || *chr == 32)
		return (1);
	else
		return (0);
}
