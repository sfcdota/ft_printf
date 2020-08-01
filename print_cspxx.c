/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:44:37 by cbach             #+#    #+#             */
/*   Updated: 2020/08/02 01:29:48 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(t_f *f)
{
	char c;
	char filler;

	if (f->width == -1)
		f->width = va_arg(f->list, int);
	c = f->type == '%' ? '%' : (char)va_arg(f->list, unsigned int);
	if (f->zero && !f->minus)
		filler = '0';
	else
		filler = ' ';
	if (f->minus)
	{
		ft_putchar_fd(c, 1, f);
		fill(f->width ? f->width - 1 : 0, filler, f);
	}
	else
	{
		fill(f->width ? f->width - 1 : 0, filler, f);
		ft_putchar_fd(c, 1, f);
	}
}

char	*ft_itoa_16(unsigned long long n, t_f *f, char *base16)
{
	char				*output;
	int					len;

	if (n == 0 && f->type == 'p')
		return (NULL);
	len = max(i16_len(n), 0, f->prec);
	if (!(output = malloc(len + 1 + (f->type == 'p' ? 2 : 0))))
		return (NULL);
	if (f->type == 'p')
	{
		output[0] = '0';
		output[1] = 'x';
	}
	output[len + (f->type == 'p' ? 2 : 0)] = '\0';
	while (len)
	{
		output[--len + (f->type == 'p' ? 2 : 0)] = base16[n % 16];
		n /= 16;
	}
	return (output);
}

void	put_triplet_pxx(char *s, int len, char filler, t_f *f)
{
	if (f->minus)
	{
		fill(f->prec - len, f->type != 'p' ? '0' : ' ', f);
		if (!(f->prec == -2 && *s == '0'))
			ft_putstr_fd_l(s, 1, len, f);
		else if (f->width)
			ft_putchar_fd(' ', 1, f);
		if (f->width > max(f->prec, 0, len))
			fill(f->width - max(f->prec, len, 0), filler, f);
	}
	else
	{
		if (f->width > max(f->prec, 0, len))
			fill(f->width - max(f->prec, len, 0), filler, f);
		if (f->prec > len && !(len == 3 && f->type == 'p' && s[2] == '0'))
			fill(f->prec - len, f->type != 'p' ? '0' : ' ', f);
		if (!(f->prec == -2 && *s == '0'))
			ft_putstr_fd_l(s, 1, len, f);
		else if (f->type == 'p')
			ft_putstr_fd_l(s, 1, len, f);
		else if (f->width)
			ft_putchar_fd(' ', 1, f);
		if (f->type == 'p' && s[2] == '0' && len == 3)
			fill(f->prec - 1 - f->width, '0', f);
	}
}

void	adjust_spxx(char *s, t_f *f, char filler)
{
	int		len;

	len = ft_strlen(s);
	f->zero = f->minus ? 0 : f->zero;
	filler = f->zero ? '0' : ' ';
	if (f->type == 's')
	{
		len = f->prec == -2 ? 0 : len;
		len = f->prec > 0 && f->prec < len ? f->prec : len;
		f->minus ? ft_putstr_fd_l(s, 1, len, f)
		: fill(max(0, f->width, len) - len, filler, f);
		f->minus ? fill(max(0, f->width, len) - len, filler, f)
		: ft_putstr_fd_l(s, 1, len, f);
	}
	else
	{
		if (f->width > max(f->prec, 0, len) && f->zero && f->prec)
		{
			f->zero = 0;
			filler = ' ';
		}
		put_triplet_pxx(s, len, filler, f);
	}
}

void	print_spxx(t_f *f)
{
	char	*str;
	int		need_free;

	if (f->type == 's')
		str = va_arg(f->list, char *);
	else if (f->type == 'x' || f->type == 'X')
		str = ft_itoa_16(va_arg(f->list, unsigned int), f,
		f->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	else
		str = ft_itoa_16((unsigned long long int)va_arg(f->list, void *), f,
		f->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	need_free = str == NULL || f->type != 's' ? 1 : 0;
	if (str == NULL)
	{
		if (f->type == 's')
			str = ft_strdup("(null)");
		else if (f->type == 'p')
			str = f->prec == -2 || f->prec == 2 ?
			ft_strdup("0x") : ft_strdup("0x0");
		else
			str = ft_strdup("");
	}
	adjust_spxx(str, f, ' ');
	if (need_free)
		free(str);
}
