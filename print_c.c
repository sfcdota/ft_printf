/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:43:47 by cbach             #+#    #+#             */
/*   Updated: 2020/07/29 21:19:23 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
flags only - allowed
*/

/*
precision not allowed
*/

/*
length only l allowed
*/

void	print_spaces(int width)
{
	if (width)
		while (--width)
			ft_putchar_fd(' ', 1);
}

int	print_c(t_format *format)
{
	if (format->flag_hash || format->flag_plus || format->flag_space ||
	format->flag_zero || format->precision || format->length == 'a' ||
	format->length == 'b' || format->length == 'h')
		return (-1);
	if (format->flag_minus)
	{
		ft_putchar_fd(va_arg(format->list, char), 1);
		print_spaces(format->width - 1);
	}
	else
	{
		print_spaces(format->width - 1);
		ft_putchar_fd(va_arg(format->list, char), 1);
	}
	return (format->width ? format->width : 1);
}
