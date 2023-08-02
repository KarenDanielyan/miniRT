/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:37 by kdaniely          #+#    #+#             */
/*   Updated: 2023/02/10 18:27:54 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(-1 * n));
	return ((unsigned int)n);
}

static int	count_digits(unsigned int digits)
{
	int	i;

	i = 1;
	while (digits > 9)
	{
		i ++;
		digits /= 10;
	}
	return (i);
}

static void	ft_strrev(char *a)
{
	char	*l;
	char	*r;
	char	temp;

	l = a;
	r = a + ft_strlen(a) - 1;
	while (l < r)
	{
		temp = *l;
		*l = *r;
		*r = temp;
		l ++;
		r --;
	}
}

static void	fill_out(char *i, unsigned int digits, int size, int sign)
{
	while (size > sign)
	{
		*i = '0' + digits % 10;
		digits /= 10;
		i ++;
		size --;
	}
	if (sign == 1)
	{
		*i = '-';
		i ++;
	}
	*i = '\0';
}

/*
*	Reference: DNE
*
*	Description: Allocates (with malloc()) and returns a string
*	representing the integer received as an argument.
*
*	Return Value: The string representing the integer.
*	NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	int				size;
	int				sign;
	unsigned int	digits;
	char			*i;
	char			*a;

	sign = (int)(n < 0);
	digits = ft_abs(n);
	size = count_digits(digits) + sign;
	a = malloc ((size + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	i = a;
	fill_out(i, digits, size, sign);
	ft_strrev(a);
	return (a);
}
