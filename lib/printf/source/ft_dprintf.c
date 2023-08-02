/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:21:30 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/31 17:54:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "helper.h"

static int	check_flag(int fd, const char *s, va_list args)
{
	int	count;

	count = 0;
	if (*s == 'd' || *s == 'i')
		count += printf_putnbr_fd(fd, va_arg(args, int));
	else if (*s == 'u')
		count += printf_putunbr_fd(fd, va_arg(args, unsigned int));
	else if (*s == 's')
		count += printf_putstr_fd(fd, va_arg(args, char *));
	else if (*s == 'c')
		count += printf_putchar_fd(fd, va_arg(args, int));
	else if (*s == 'p')
	{
		write(fd, "0x", 2);
		count += printf_putptr_fd(fd, va_arg(args, uintptr_t), L_HEX) + 2;
	}
	else if (*s == 'x' || *s == 'X')
		count += printf_puthex_fd(fd, va_arg(args, unsigned int), s);
	else if (*s == '%')
	{
		count += 1;
		write(fd, "%", 1);
	}
	return (count);
}

static char	*on_f(int fd, char *s, va_list args, int *count)
{
	if (*s == '%')
	{
		s++;
		while (*s && !printf_strchr(FORMAT_FLAGS, *s)
			&& !printf_strchr(ESCAPE_SEQ, *s))
			s ++;
		if (printf_strchr(FORMAT_FLAGS, *s))
			*count += check_flag(fd, s, args);
		else if (printf_strchr(ESCAPE_SEQ, *s))
		{
			write(fd, s, 1);
			(*count)++;
		}
		s++;
	}
	return (s);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;
	char	*s;
	char	*tmp;

	va_start(args, str);
	if (!str)
		return (0);
	count = 0;
	s = (char *)str;
	while (*s)
	{
		tmp = on_f(fd, s, args, &count);
		if (tmp == s)
		{
			write(fd, s, 1);
			s ++;
			count ++;
		}
		else
			s = tmp;
	}
	va_end(args);
	return (count);
}
