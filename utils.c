/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:38:44 by cbach             #+#    #+#             */
/*   Updated: 2020/08/02 01:18:53 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_f			*discard_options(t_f *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->width = 0;
	f->prec = 0;
	f->length = 0;
	f->type = 0;
	return (f);
}

void		fill(int len, char filler, t_f *f)
{
	if (len > 0)
		while (len--)
			ft_putchar_fd(filler, 1, f);
}

int			i_len(long long int i)
{
	int len;

	len = 1 + (i < 0 ? 1 : 0);
	i = i < 0 ? -i : i;
	while (i > 10)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int			i16_len(unsigned long long int i)
{
	int len;

	len = 1;
	while (i >= 16)
	{
		i /= 16;
		len++;
	}
	return (len);
}

char		*next_field(char *s)
{
	while (*s && ft_isdigit(*s))
		s++;
	return (s);
}
