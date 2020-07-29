/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:23 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 00:49:02 by cbach            ###   ########.fr       */
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

void	ft_putnbrlli_fd(long long int n, int fd)
{
	if (n == -9223372036854775808)
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

void	fill_diu(int len, char filler)
{
	if (len)
		while (--len)
			ft_putchar_fd(filler, 1);
}

int		adjust_di(long long int n, t_format *format)
{
	char	filler;
	char	prepender;
	int		len;

	prepender = '\0';
	format->flag_zero = format->flag_minus ? 0 : format->flag_zero;
	if (format->flag_space)
		prepender = n >= 0 ? ' ' : '-'
	if (format->flag_plus)
		prepender = n >= 0 ? '+' : '-';
	format->flag_space = format->flag_plus ? 0 : format->flag_space;
	filler = format->flag_zero ? '0' : ' ';
	if (prepender)
		ft_putchar_fd(prepender, 1);
	if (format->flag_minus)
	{
		fill_diu(max(format->precision, format->width, n) - i_len(n));
		ft_putnbrlli_fd(n);
	}
	else
	{
		ft_putnbrlli_fd(n);
		fill_diu(max(format->precision, format->width, n) - i_len(n));
	}
	return (fill_diu(max(format->precision, format->width, n) - i_len(n)) + prepender ? 1 : 0);
}

int		adjust_u(unsigned long long int n, t_format *t_format)
{

}

int		print_d(t_format *format)
{
	long long int	out;
	unsigned long long int outu;
	int				len;

	if (format->flag_hash)
		return (-1);
	out = 0;
	outl = 0;
	if (format->type == 'u')
	{
		outu = format->length == 'l' ? va_arg(format->list, unsigned long int);
		outu = format->length == 'll' ? va_arg(format->list, unsigned long long int);
		outu = format->length == 'h' ? va_arg(format->list, unsigned short int);
		outu = format->length == 'hh' ? va_arg(format->list, unsigned char);
		len = ui_len(outu);
	}
	if (format->type == 'd' || format->type == 'i')
	{
		out = format->length == 'l' ? va_arg(format->list, long int);
		out = format->length == 'll' ? va_arg(format->list, long long int);
		out = format->length == 'h' ? va_arg(format->list, short int);
		out = format->length == 'hh' ? va_arg(format->list, signed char);
		len = i_len(out);
	}
	return (len);
}
