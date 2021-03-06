/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:55:34 by mazoukni          #+#    #+#             */
/*   Updated: 2020/02/12 05:36:23 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct		s_flag{
	int value;
	int state;
}					t_flag;

typedef struct		s_flags
{
	t_flag width;
	t_flag prec;
	t_flag zero;
}					t_flags;

int					ft_atoi(const char *str);
void				ft_bzero(void *str, int n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
size_t				ft_strnlen(const char *str, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *str, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
int				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find,
				size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int nb);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *str, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char *s, char(*f)(unsigned int, char));
void				insert_element(char *str, char **tab, int i, char c);
char				*ft_itoa(int nb);
void				ft_putchar(char c);
void				ft_putnbr(long nb);
void				ft_swap(int *a, int *b);
void				ft_putstr(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strstr(char *str, char *to_find);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strrev(char *str);
char				*ft_dectohex(char format, size_t decimal);
int					ft_hextodec(int hex);
void				print_hex(char *format, va_list argp, t_flags wpz, int *a);
void				print_string(va_list argp, t_flags wpz, int *a);
void				print_decint(char *format, va_list argp, t_flags wpz,
int *a);
void				print_pointer(va_list argp, t_flags wpz, int *a);
t_flag				fetch_zero(char *format, va_list argp);
t_flag				fetch_prec(char *format, va_list argp);
t_flag				fetch_width(char *format, va_list argp);
char const			*choose_flag(char *format, va_list argp, int *a);
int					ft_nbrlen(long integer);
void				ft_hexatoi(size_t u, char a);
int					ft_hexlen(size_t integer);
void				print_prec(t_flags wpz, int *a);

#endif
