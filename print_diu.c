/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:23 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 01:48:22 by cbach            ###   ########.fr       */
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

void	ft_putnbrlli_fd(long long int n, int fd)
{
	if (n == -9223372036854775807LL -1LL)
		ft_putstr_fd("−9223372036854775808", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}

void	ft_putnbrull_fd(unsigned long long int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void	put_triplet_diu(char *s, int len, char filler, t_f *f)
{

}

int		adjust_di(long long int n, t_f *f)
{
	char	filler;
	int		len;

	f->zero = f->minus || (f->width && f->prec) ? 0 : f->zero;
	filler = f->zero ? '0' : ' ';

	len = n < 0 && f->zero && !f->width ? -1 : 0;
	if (n < 0 && (f->zero || f->prec) && f->width < f->prec + i_len(n))
	{
		ft_putchar_fd('-', 1);
		n = -n;
		f->width--;
	}
	len += f->zero ? ui_len(n) : i_len(n);
	if (f->minus)
	{
		fill(f->prec - len, '0');
		ft_putnbrlli_fd(n, 1);
		fill(f->width - max(len, f->prec, 0), filler);
	}
	else
	{
		fill(f->width - max(len, f->prec, 0), filler);
		fill(f->prec - len, '0');
		ft_putnbrlli_fd(n, 1);
	}
	return (max(f->prec, f->width, len));
}

int		print_diu(t_f *f)
{
	long long int	out;

	out = f->type == 'u' ? (long long int)va_arg(f->list, unsigned int) : (long long int)va_arg(f->list, int);
	return (adjust_di(out, f));
}
