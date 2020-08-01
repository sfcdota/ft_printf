/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:44:37 by cbach             #+#    #+#             */
/*   Updated: 2020/08/01 16:18:55 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_c(t_f *f)
{
	char c;

	if (f->type == '%')
		ft_putchar_fd('%', 1, f);
	else
	{
		if (f->width == -1)
			f->width = va_arg(f->list, int);
		c = (char)va_arg(f->list, unsigned int);
		if (f->minus)
		{
			ft_putchar_fd(c, 1, f);
			fill(f->width ? f->width - 1 : 0, ' ', f);
		}
		else
		{
			fill(f->width ? f->width - 1 : 0, ' ', f);
			ft_putchar_fd(c, 1, f);
		}
	}
}

char	*ft_itoa_16(unsigned long long n, t_f *f)
{
	char				*output;
	int					len;
	char				*base16;

	if (n == 0 && f->type == 'p')
		return (NULL);
	len = max(i16_len(n), 0, f->prec);
	base16 = f->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	f->hash = f->type == 'p' ? 1 : 0;
	if (!(output = malloc(len + 1 + (f->hash ? 2 : 0))))
		return (NULL);
	if (f->hash)
	{
		output[1] = f->type == 'X' ? 'X' : 'x';
		output[0] = '0';
	}
	output[len + (f->hash ? 2 : 0)] = '\0';
	while (len)
	{
		output[--len + (f->hash ? 2 : 0)] = base16[n % 16];
		n /= 16;
	}
	return (output);
}

void	put_triplet_pxx(char *s, int len, char filler, t_f *f)
{
	int is_num;

	is_num = ft_strchr("xX", f->type) ? 1 : 0;
	if (f->minus)
	{
		if (f->prec > len)
			fill(f->prec - len, is_num ? '0' : ' ', f);
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
		if (f->prec > len)
			fill(f->prec - len, is_num ? '0' : ' ', f);
		if (!(f->prec == -2 && *s == '0'))
			ft_putstr_fd_l(s, 1, len, f);
		else if (f->width)
			ft_putchar_fd(' ', 1, f);
	}
}

void		adjust_spxx(char *s, t_f *f, char filler)
{
	int		len;

	len = ft_strlen(s);
	f->zero = f->minus ? 0 : f->zero;
	filler = f->zero && f->type != 's' ? '0' : ' ';
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
		if (f->width > max(f->prec,0, len) && f->zero && f->prec)
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
	char	filler;

	str = f->type == 's' ? va_arg(f->list, char *)
	: ft_itoa_16((unsigned long long int)va_arg(f->list, void *), f);
	need_free = str == NULL || f->type != 's' ? 1 : 0;
	if (str == NULL)
	{
		if (f->type == 's')
			str = f->prec < (int)ft_strlen("(null)") && f->prec > 0
			? ft_strdup("") : ft_strdup("(null)");
		else if (f->type == 'p')
			str = f->prec < (int)ft_strlen("(nil)") && f->prec > 0
			? ft_strdup("") : ft_strdup("(nil)");
		else
			str = ft_strdup("");
	}
	filler = ' ';
	adjust_spxx(str, f, filler);
	if (need_free)
		free(str);
}
