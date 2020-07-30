/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:43:47 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 11:57:01 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	fill_c(int len)
{
	if (len)
		while (--len)
			ft_putchar_fd(' ', 1);
}

int	print_c(t_format *format)
{
	if (format->width == -1)
		format->width = va_arg(format->list, int);
	if (format->flag_minus)
	{
		ft_putchar_fd(format->length == 'l' ? va_arg(format->list, unsigned long int) : va_arg(format->list, unsigned int), 1);
		print_spaces(format->width - 1);
	}
	else
	{
		print_spaces(format->width - 1);
		ft_putchar_fd(format->length == 'l' ? va_arg(format->list, unsigned long int) : va_arg(format->list, unsigned int), 1);
	}
	return (format->width ? format->width : 1);
}
