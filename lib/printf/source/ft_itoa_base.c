/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:37 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 17:19:57 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

static unsigned long	ft_abs(long n)
{
	if (n < 0)
		return ((unsigned long)(-1 * n));
	return ((unsigned long)n);
}

static long	count_digits(unsigned long digits, const char *base)
{
	long			i;
	unsigned long	base_len;

	i = 1;
	base_len = (long )(printf_strlen(base) - 1);
	while (digits > base_len)
	{
		i ++;
		digits /= (base_len + 1);
	}
	return (i);
}

static void	ft_strrev(char *a)
{
	char	*l;
	char	*r;
	char	temp;

	l = a;
	r = a + printf_strlen(a) - 1;
	while (l < r)
	{
		temp = *l;
		*l = *r;
		*r = temp;
		l ++;
		r --;
	}
}

static char	*fill_out(unsigned long digits, long size,
				long sign, const char *base)
{
	char	*a;
	char	*i;
	long	base_len;

	base_len = printf_strlen(base);
	a = malloc ((size + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	i = a;
	while (size > sign)
	{
		*i = *(base + (digits % base_len));
		digits /= base_len;
		i ++;
		size --;
	}
	if (sign == 1)
	{
		*i = '-';
		i ++;
	}
	*i = '\0';
	return (a);
}

char	*printf_itoa_base(long n, const char *base)
{
	long			size;
	long			sign;
	unsigned long	digits;
	char			*a;

	sign = (long)(n < 0);
	digits = ft_abs(n);
	size = count_digits(digits, base) + sign;
	a = fill_out(digits, size, sign, base);
	ft_strrev(a);
	return (a);
}
