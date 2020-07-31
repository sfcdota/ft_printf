/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:44:37 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 14:17:09 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_c(t_f *f)
{
	char c;

	if (f->type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (f->width == -1)
		f->width = va_arg(f->list, int);
	c = (char)va_arg(f->list, unsigned int);
	if (f->minus)
	{
		ft_putchar_fd(c, 1);
		fill(f->width ? f->width - 1 : 0, ' ');
	}
	else
	{
		fill(f->width ? f->width - 1 : 0, ' ');
		ft_putchar_fd(c, 1);
	}
	return (f->width ? f->width : 1);
}

char	*ft_itoa_16(unsigned long long n, t_f *f)
{
	char				*output;
	int					len;
	char				*base16;

	if (n == 0 && f->type == 'p')
		return (NULL);
	len = i16_len(n);
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
	while (n >= 16)
	{
		output[--len + (f->hash ? 2 : 0)] = base16[n % 16];
		n /= 16;
	}
	output[--len + (f->hash ? 2 : 0)] = base16[n % 16];
	return (output);
}

void	put_triplet_pxx(char *s, int len, char filler, t_f *f)
{
	int is_num;

	is_num = ft_strchr("xX", f->type) ? 1 : 0;
	if (f->minus)
	{
		if (f->prec > len)
			fill(f->prec - len, is_num ? '0' : ' ');
		if (f->prec != -2)
			ft_putstr_fd_l(s, 1, len);
		if (f->width > f->prec + len)
			fill(f->width - max(f->prec, len, 0), filler);
	}
	else
	{
		if (f->width > f->prec + len)
			fill(f->width - max(f->prec, len, 0), filler);
		if (f->prec > len)
			fill(f->prec - len, is_num ? '0' : ' ');
		if (f->prec != -2)
			ft_putstr_fd_l(s, 1, len);
	}
}

int		adjust_spxx(char *s, t_f *f, char filler)
{
	int		len;

	len = ft_strlen(s);
	f->zero = f->minus ? 0 : f->zero;
	filler = f->zero ? '0' : ' ';
	len = f->prec == -2 ? 0 : len;
	if (f->type == 's')
	{
		len = f->prec > 0 && f->prec < len ? f->prec : len;
		f->minus ? ft_putstr_fd_l(s, 1, len)
		: fill(max(0, f->width, len) - len, filler);
		f->minus ? fill(max(0, f->width, len) - len, filler)
		: ft_putstr_fd_l(s, 1, len);
		return (max(0, len, f->width));
	}
	else
	{
		if (f->width > f->prec + len && f->zero && f->prec)
		{
			f->zero = 0;
			filler = ' ';
		}
		put_triplet_pxx(s, len, filler, f);
		return (max(f->prec, f->width, len));
	}
}

int		print_spxx(t_f *f)
{
	char	*str;
	int		status;
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
	status = adjust_spxx(str, f, filler);
	if (need_free)
		free(str);
	return (status);
}
