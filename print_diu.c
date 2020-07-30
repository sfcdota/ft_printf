/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:23 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 16:20:45 by cbach            ###   ########.fr       */
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

int		adjust_di(long long int n, t_format *format)
{
	char	filler;
	char	prepender;

	prepender = '\0';
	format->flag_zero = format->flag_minus ? 0 : format->flag_zero;
	filler = format->flag_zero ? '0' : ' ';
	if (prepender)
		ft_putchar_fd(prepender, 1);
	if (format->flag_minus)
	{
		fill(max(format->precision, format->width, i_len(n)) - i_len(n), filler);
		ft_putnbrlli_fd(n, 1);
	}
	else
	{
		ft_putnbrlli_fd(n, 1);
		fill(max(format->precision, format->width, i_len(n)) - i_len(n), filler);
	}
	return (max(format->precision, format->width, i_len(n)) + (prepender ? 1 : 0));
}

int		print_diu(t_format *format)
{
	long long int	out;

	if (format->width == -1)
		format->width = va_arg(format->list, int);
	if (format->precision == -1)
		format->precision = va_arg(format->list, int);
	out = format->type == 'u' ? va_arg(format->list, unsigned int) : va_arg(format->list, int);

	return (adjust_di(out, format));
}
