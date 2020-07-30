/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:43:47 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 00:54:57 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_c(t_f *f)
{
	char c;

	if (f->type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (f->width == -1)
		f->width = va_arg(f->list, int);
	c = (char)va_arg(f->list, unsigned int);

	if (f->minus)
	{
		ft_putchar_fd(c, 1);
		fill(f->width ? f->width - 1 : 0, ' ');
	}
	else
	{
		fill(f->width ? f->width - 1: 0, ' ');
		ft_putchar_fd(c, 1);
	}
	return (f->width ? f->width : 1);
}
