/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:13 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 16:20:10 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_16(unsigned long long n, t_format *format)
{
	char				*output;
	int					len;
	char				*base16;

	len = i_len(n);
	base16 = format->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	if (!(output = malloc(len + 1 + (format->flag_hash ? 2 : 0))))
		return (NULL);
	output[len] = '\0';
	while (n >= 16)
	{
		output[--len] = base16[n % 16];
		n /= 16;
	}
	output[--len] = base16[n % 16];
	if (format->flag_hash)
	{
		output[1] = format->type == 'x' ? 'x' : 'X';
		output[0] = '0';
	}
	return (output);
}

int		adjust_spxX(char *s, t_format *format)
{
	char	filler;
	char	prepender;
	int		len;

	len = ft_strlen(s);
	prepender = '\0';
	format->flag_zero = format->flag_minus ? 0 : format->flag_zero;
	filler = format->flag_zero ? '0' : ' ';
	if (prepender)
		ft_putchar_fd(prepender, 1);
	if (format->flag_minus)
	{
		fill(max(format->precision, format->width, len) - len, filler);
		ft_putstr_fd(s, 1);
	}
	else
	{
		ft_putstr_fd(s, 1);
		fill(max(format->precision, format->width, len) - len, filler);
	}
	free(s);
	return (max(format->precision, format->width, len) + (prepender ? 1 : 0));
}

int	print_spxX(t_format *format)
{
	char					*str;

	format->flag_hash = format->type == 'p' ? 1 : format->flag_hash;
	str = format->type == 's' ? va_arg(format->list, char *) : ft_itoa_16((unsigned long long int)va_arg(format->list, void *), format);
	str = str == NULL ? ft_strdup("(null)") : str;
	return (adjust_spxX(str, format));
}
