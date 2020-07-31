/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:25:44 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 14:17:32 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_arg(t_f *f)
{
	int len;

	len = 0;
	len = f->type == 'c' ? print_c(f) : len;
	len = f->type == 's' ? print_spxx(f) : len;
	len = f->type == 'p' ? print_spxx(f) : len;
	len = f->type == 'd' ? print_diu(f) : len;
	len = f->type == 'i' ? print_diu(f) : len;
	len = f->type == 'u' ? print_diu(f) : len;
	len = f->type == 'x' ? print_spxx(f) : len;
	len = f->type == 'X' ? print_spxx(f) : len;
	len = f->type == '%' ? print_c(f) : len;
	return (len);
}

int		handle(char *line, t_f *f)
{
	int len;
	int temp;

	len = 0;
	while (*line && len >= 0)
	{
		if (*line != '%')
		{
			ft_putchar_fd(*line++, 1);
			len++;
		}
		else
		{
			line++;
			if ((temp = handle_flags(&line, discard_options(f))) == -1)
				return (-1);
			len = temp != -1 ? len + temp : temp;
		}
	}
	return (len);
}

int		ft_printf(const char *line, ...)
{
	int status;
	t_f	f;

	if (!line)
		return (-1);
	va_start(discard_options(&f)->list, line);
	status = handle((char *)line, &f);
	va_end(f.list);
	return (status);
}
