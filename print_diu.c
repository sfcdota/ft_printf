/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:23 by cbach             #+#    #+#             */
/*   Updated: 2020/08/01 14:43:40 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		return (c);
	}
	if (b > c)
		return (b);
	return (c);
}

int		min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		return (c);
	}
	if (b < c)
		return (b);
	return (c);
}

void	neg_triplet_not_minus(long long int n, int len, char filler, t_f *f)
{
	if (filler == '0')
	{
		ft_putchar_fd('-', 1, f);
		len--;
		n = -n;
		f->width--;
	}
	else if (f->prec >= len)
		f->width--;
	fill(f->width - max(f->prec, len, 0), filler, f);
	if (filler == ' ')
	{
		ft_putchar_fd('-', 1, f);
		len--;
		n = -n;
	}
	if (f->prec > len)
		fill(f->prec - len, '0', f);
	if (f->prec != -2 || n)
		ft_putnbrll_fd(n, 1, f);
}

void	put_triplet_diu(long long int n, int len, char filler, t_f *f)
{
	if (n == 0 && f->width && f->prec == -2 && filler == ' ')
		len--;
	if (f->minus)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1, f);
			len--;
			n = -n;
			f->width--;
		}
		f->prec > len ? fill(f->prec - len, '0', f) : NULL;
		f->prec != -2 || n? ft_putnbrll_fd(n, 1, f) : NULL;
		fill(f->width - max(f->prec, len, 0), filler, f);
	}
	else if (n >= 0)
	{
		fill(f->width - max(f->prec, len, 0), filler, f);
		f->prec > len ? fill(f->prec - len, '0', f) : NULL;
		f->prec == -2 && !n ? NULL : ft_putnbrll_fd(n, 1, f);
	}
	else
		neg_triplet_not_minus(n, len, filler, f);
}

int		print_diu(t_f *f)
{
	long long int	out;

	out = f->type == 'u' ? (long long int)va_arg(f->list, unsigned int)
	: (long long int)va_arg(f->list, int);
	put_triplet_diu(
	out, i_len(out), f->zero && !f->minus && !f->prec ? '0' : ' ', f);
	return (f->return_v);
}
