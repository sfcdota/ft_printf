/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:43:47 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 16:19:50 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_c(t_format *format)
{
	char c;

	if (format->width == -1)
		format->width = va_arg(format->list, int);
	c = format->type == '%' ? '%' : (char)va_arg(format->list, unsigned int);
	if (format->flag_minus)
	{
		ft_putchar_fd(c, 1);
		fill(format->width ? format->width : 0, ' ');
	}
	else
	{
		fill(format->width ? format->width : 0, ' ');
		ft_putchar_fd(c, 1);
	}
	return (format->width ? format->width : 1);
}
