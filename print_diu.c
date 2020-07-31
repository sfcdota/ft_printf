/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:23 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 14:17:22 by cbach            ###   ########.fr       */
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
		ft_putchar_fd('-', 1);
		len--;
		n = -n;
		f->width--;
	}
	else if (f->prec > len)
		f->width--;
	fill(f->width - max(f->prec, len, 0), filler);
	if (filler == ' ')
	{
		ft_putchar_fd('-', 1);
		len--;
		n = -n;
	}
	if (f->prec > len)
		fill(f->prec - len, '0');
	if (f->prec != -2)
		ft_putnbrll_fd(n, 1);
}

void	put_triplet_diu(long long int n, int len, char filler, t_f *f)
{
	if (n == 0 && f->width && f->prec == -2 && filler == ' ')
		len--;
	if (f->minus)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			len--;
			n = -n;
			f->width--;
		}
		f->prec > len ? fill(f->prec - len, '0') : NULL;
		f->prec != -2 ? ft_putnbrll_fd(n, 1) : NULL;
		fill(f->width - max(f->prec, len, 0), filler);
	}
	else if (n >= 0)
	{
		fill(f->width - max(f->prec, len, 0), filler);
		f->prec > len ? fill(f->prec - len, '0') : NULL;
		f->prec != -2 ? ft_putnbrll_fd(n, 1) : NULL;
	}
	else
		neg_triplet_not_minus(n, len, filler, f);
}

int		print_diu(t_f *f)
{
	long long int	out;
	int				status;

	out = f->type == 'u' ? (long long int)va_arg(f->list, unsigned int)
	: (long long int)va_arg(f->list, int);
	status = max(f->prec, f->width, i_len(out));
	put_triplet_diu(
	out, i_len(out), f->zero && !f->minus && !f->prec ? '0' : ' ', f);
	return (status);
}
