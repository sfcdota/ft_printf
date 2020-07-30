/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:26:15 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 01:24:16 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
#include <stdio.h>

typedef struct	s_f
{
	va_list		list;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	int			width;
	int			prec;
	char		length;
	char		type;

}				t_f;

t_f				*discard_options(t_f *f);
char			*ft_itoa_16(unsigned long long n, t_f *f);
int				ft_printf(const char *line, ...);
int				handle(char *line, t_f *f);
int				minus(char c, t_f *f);
int				zero(char c, t_f *f);
int				i_len(long long int i);
int				ui_len(unsigned long long int i);
int				i16_len(unsigned long long int i);
void			fill(int len, char filler);
int				print_c(t_f *f);
int				min(int a, int b, int c);
int				max(int a, int b, int c);
void			ft_putnbrlli_fd(long long int n, int fd);
void			ft_putnbrull_fd(unsigned long long int n, int fd);
int				adjust_di(long long int n, t_f *f);
int				adjust_u(unsigned long long int n, t_f *f);
int				print_diu(t_f *f);
int				print_spxX(t_f *f);
int				handle(char *line, t_f *f);
int				handle_flags(char **line, t_f *f);
int				handle_width(char **line, t_f *f);
int				handle_prec(char **line, t_f *f);
int				handle_length(char **line, t_f *f);
int				handle_type(char **line, t_f *f);
int				print_arg(t_f *f);


int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
#endif
