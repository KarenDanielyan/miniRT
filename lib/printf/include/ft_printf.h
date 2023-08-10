/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:47:39 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/10 17:56:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/* Description: My version of glibc printf. */
int		ft_printf(const char *s, ...);
/* Description: My version of glibc dprintf. */
int		ft_dprintf(int fd, const char *s, ...);
/* Decription: My version of glibc vdprintf */
int		ft_vdprintf(int fd, const char *str, va_list args);

#endif
