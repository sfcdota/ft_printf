/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:23 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 12:00:35 by cbach            ###   ########.fr       */
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
		prepender = n >= 0 ? ' ' : '-';
	if (format->flag_plus)
		prepender = n >= 0 ? '+' : '-';
	format->flag_space = format->flag_plus ? 0 : format->flag_space;
	filler = format->flag_zero ? '0' : ' ';
	if (prepender)
		ft_putchar_fd(prepender, 1);
	if (format->flag_minus)
	{
		fill_diu(max(format->precision, format->width, i_len(n)) - i_len(n), filler);
		ft_putnbrlli_fd(n, 1);
	}
	else
	{
		ft_putnbrlli_fd(n, 1);
		fill_diu(max(format->precision, format->width, i_len(n)) - i_len(n), filler);
	}
	return (max(format->precision, format->width, i_len(n)) - i_len(n) + prepender ? 1 : 0);
}

int		adjust_u(unsigned long long int n, t_format *format)
{
	char	filler;
	char	prepender;
	int		len;

	prepender = '\0';
	format->flag_zero = format->flag_minus ? 0 : format->flag_zero;
	if (format->flag_space)
		prepender = n >= 0 ? ' ' : '-';
	if (format->flag_plus)
		prepender = n >= 0 ? '+' : '-';
	format->flag_space = format->flag_plus ? 0 : format->flag_space;
	filler = format->flag_zero ? '0' : ' ';
	if (prepender)
		ft_putchar_fd(prepender, 1);
	if (format->flag_minus)
	{
		fill_diu(max(format->precision, format->width, i_len(n)) - i_len(n), filler);
		ft_putnbrlli_fd(n, 1);
	}
	else
	{
		ft_putnbrlli_fd(n, 1);
		fill_diu(max(format->precision, format->width, i_len(n)) - i_len(n), filler);
	}
	return (max(format->precision, format->width, i_len(n)) - i_len(n) + prepender ? 1 : 0);
}

int		print_d(t_format *format)
{
	long long int	out;
	unsigned long long int outu;
	int				len;

	if (format->width == -1)
		format->width = va_arg(format->list, int);
	if (format->precision == -1)
		format->precision = va_arg(format->list, int);
	out = 0;
	outu = 0;
	if (format->type == 'u')
	{
		outu = format->length == 'l' ? va_arg(format->list, unsigned long int) : outu;
		outu = format->length == 'll' ? va_arg(format->list, unsigned long long int) : outu;
		outu = format->length == 'h' ? va_arg(format->list, unsigned short int) : outu;
		outu = format->length == 'hh' ? va_arg(format->list, unsigned char) : outu;
		len = ui_len(outu);
	}
	if (format->type == 'd' || format->type == 'i')
	{
		out = format->length == 'l' ? va_arg(format->list, long int) : out;
		out = format->length == 'll' ? va_arg(format->list, long long int) : out;
		out = format->length == 'h' ? va_arg(format->list, short int) : out;
		out = format->length == 'hh' ? va_arg(format->list, signed char) : out;
		len = i_len(out);
	}
	return (len);
}
