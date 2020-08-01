/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:25:44 by cbach             #+#    #+#             */
/*   Updated: 2020/08/01 13:15:26 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_arg(t_f *f)
{
	if (f->type == 'c')
		print_c(f);
	if (f->type == 's')
		print_spxx(f);
	if (f->type == 'p')
		print_spxx(f);
	if (f->type == 'd')
		print_diu(f);
	if (f->type == 'i')
		print_diu(f);
	if (f->type == 'u')
		print_diu(f);
	if (f->type == 'x')
		print_spxx(f);
	if (f->type == 'X')
		print_spxx(f);
	if (f->type == '%')
		print_c(f);
}

int		handle(char *line, t_f *f)
{
	while (*line && f->return_v >= 0)
	{
		if (*line != '%')
		{
			ft_putchar_fd(*line++, 1, f);
		}
		else
		{
			line++;
			handle_flags(&line, discard_options(f));
		}
	}
	return (f->return_v);
}

int		ft_printf(const char *line, ...)
{
	int status;
	t_f	f;

	if (!line)
		return (-1);
	f.return_v = 0;
	va_start(discard_options(&f)->list, line);
	status = handle((char *)line, &f);
	va_end(f.list);
	return (status);
}
