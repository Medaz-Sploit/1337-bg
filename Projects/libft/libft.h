/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:43:06 by mazoukni          #+#    #+#             */
/*   Updated: 2019/10/15 05:34:05 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int			ft_atoi(const char *str);
void		ft_bzero(void *str, int n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(void *s, int c, int n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, void *src, int n);
void		*ft_memmove(void *dst, void *src, int n);
void		*ft_memset(void *b, int c, int len);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *str, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t n);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
#endif
