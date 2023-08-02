/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:49:40 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/31 17:54:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "helper.h"

static int	check_flag(const char *s, va_list args)
{
	int	count;

	count = 0;
	if (*s == 'd' || *s == 'i')
		count += printf_putnbr_fd(1, va_arg(args, int));
	else if (*s == 'u')
		count += printf_putunbr_fd(1, va_arg(args, unsigned int));
	else if (*s == 's')
		count += printf_putstr_fd(1, va_arg(args, char *));
	else if (*s == 'c')
		count += printf_putchar_fd(1, va_arg(args, int));
	else if (*s == 'p')
	{
		write(STDOUT_FILENO, "0x", 2);
		count += printf_putptr_fd(1, va_arg(args, uintptr_t), L_HEX) + 2;
	}
	else if (*s == 'x' || *s == 'X')
		count += printf_puthex_fd(1, va_arg(args, unsigned int), s);
	else if (*s == '%')
	{
		count += 1;
		write(STDOUT_FILENO, "%", 1);
	}
	return (count);
}

static char	*on_f(char *s, va_list args, int *count)
{
	if (*s == '%')
	{
		s++;
		while (*s && !printf_strchr(FORMAT_FLAGS, *s)
			&& !printf_strchr(ESCAPE_SEQ, *s))
			s ++;
		if (printf_strchr(FORMAT_FLAGS, *s))
			*count += check_flag(s, args);
		else if (printf_strchr(ESCAPE_SEQ, *s))
		{
			write(STDOUT_FILENO, s, 1);
			(*count)++;
		}
		s++;
	}
	return (s);
}

int	ft_printf(const char *str, ...)
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
		tmp = on_f(s, args, &count);
		if (tmp == s)
		{
			write(STDOUT_FILENO, s, 1);
			s ++;
			count ++;
		}
		else
			s = tmp;
	}
	va_end(args);
	return (count);
}
