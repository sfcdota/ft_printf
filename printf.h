/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:26:15 by cbach             #+#    #+#             */
/*   Updated: 2020/07/29 20:15:31 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
// a = ll
// b = hh
# define TYPES "cspdiuxXnfge"
# define FLAGS "-+ 0#"
typedef struct	s_format
{
	va_list		list;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			flag_zero;
	int			flag_hash;
	int			width;
	int			precision;
	int			length;
	char		type;

}				t_format;

char			*ft_itoa_16(unsigned long long n, int lowercase);
int				ft_printf(const char *line, ...);
int				handle(char *line, t_format *format);
t_format		*discard_options(t_format *format);
int				minus(char c, t_format *format);
int				plus(char c, t_format *format);
int				zero(char c, t_format *format);
int				hash(char c, t_format *format);
int				space(char c, t_format *format);
int				i_len(long long int i);
#endif
