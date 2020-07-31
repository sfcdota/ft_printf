/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:26:15 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 14:13:00 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <stdarg.h>

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
int				i16_len(unsigned long long int i);
void			fill(int len, char filler);
int				print_c(t_f *f);
int				min(int a, int b, int c);
int				max(int a, int b, int c);
int				print_diu(t_f *f);
int				print_spxx(t_f *f);
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
void			ft_putnbrll_fd(long long int n, int fd);
char			*ft_strchr(const char *s, int c);
void			ft_putstr_fd_l(char *s, int fd, size_t len);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
char			*next_field(char *s);
#endif
