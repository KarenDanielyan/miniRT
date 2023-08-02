/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:24:44 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 17:16:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

# define OFFSET			'0'
# define FORMAT_FLAGS 	"cspdiuxX%"
# define ESCAPE_SEQ		"\\\"\t\b\a\?\r\f\v\n"
# define DECIMAL		"0123456789"
# define OCTAL			"01234567"
# define B_HEX			"0123456789ABCDEF"
# define L_HEX			"0123456789abcdef"

/* Helper Functions */
char	*printf_itoa_base(long n, const char *base);
char	*printf_strchr(const char *str, int c);

int		printf_putchar_fd(int fd, char c);
int		printf_putunbr_fd(int fd, unsigned int nbr);
int		printf_putnbr_fd(int fd, int nbr);
int		printf_putptr_fd(int fd, uintptr_t ptr, char *base);
int		printf_putstr_fd(int fd, char *str);
int		printf_puthex_fd(int fd, unsigned int nbr, const char *f_str);

size_t	printf_strlen(const char *str);

#endif
