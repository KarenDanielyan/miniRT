/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:21:00 by kdaniely          #+#    #+#             */
/*   Updated: 2023/07/24 18:10:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "get_next_line.h"

/* Glibc Functions */
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(const void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

char		*ft_strdup(const char *s);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strnstr(const char *big, const char *little, size_t len);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_iswhitespace(char c);
int			ft_atoi(const char *str);
int			ft_strappend(char **str, char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t size);
int			ft_strlen_2d(char const **s);
int64_t		ft_atol(const char *s);
uint64_t	ft_atul(const char *s);

/* Additional Functions */
void		free_2d(char **s);
void		ft_swap(void **a, void **b);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		*ft_itoa(int n);
char		*ft_itul(uint64_t n);
char		*ft_itol(long long n);
char		**ft_strdup_2d(char const **s);
char		**ft_split(char const *s, char c);
char		**ft_split_2(char const *s, char *charset);
char		*ft_strjoin_free(char *s1, char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Get next line */
char		*get_next_line(int fd);
#endif
