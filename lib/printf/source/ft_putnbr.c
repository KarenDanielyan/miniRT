/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:50:08 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 17:19:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	printf_putunbr_fd(int fd, unsigned int nbr)
{
	char	*num;
	int		count;

	num = printf_itoa_base(nbr, DECIMAL);
	count = printf_putstr_fd(fd, num);
	free(num);
	return (count);
}

int	printf_putnbr_fd(int fd, int nbr)
{
	char	*num;
	int		count;

	count = 0;
	num = printf_itoa_base(nbr, DECIMAL);
	count += printf_putstr_fd(fd, num);
	free(num);
	return (count);
}

int	printf_putptr_fd(int fd, uintptr_t ptr, char *base)
{
	uintptr_t	temp;
	uintptr_t	base_len;	
	int			count;

	temp = ptr;
	count = 0;
	base_len = printf_strlen(base);
	if (temp > (base_len - 1))
	{
		count += printf_putptr_fd(fd, temp / base_len, base);
		count += printf_putptr_fd(fd, temp % base_len, base);
	}
	else
	{
		write(fd, (base + temp), 1);
		count ++;
	}
	return (count);
}

int	printf_puthex_fd(int fd, unsigned int nbr, const char *f_str)
{
	char	*num;
	int		count;

	count = 0;
	if (*f_str == 'x')
		num = printf_itoa_base(nbr, L_HEX);
	else
		num = printf_itoa_base(nbr, B_HEX);
	count += printf_putstr_fd(fd, num);
	free(num);
	return (count);
}
