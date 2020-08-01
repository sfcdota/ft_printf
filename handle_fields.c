/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fields.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:43:37 by cbach             #+#    #+#             */
/*   Updated: 2020/08/01 15:56:03 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_type(char **line, t_f *f)
{
	if (!ft_strchr("cspdiuxX%%", **line))
		f->return_v = -1;
	else
	{
		f->type = **line == 'c' ? 'c' : f->type;
		f->type = **line == 's' ? 's' : f->type;
		f->type = **line == 'p' ? 'p' : f->type;
		f->type = **line == 'd' ? 'd' : f->type;
		f->type = **line == 'i' ? 'i' : f->type;
		f->type = **line == 'u' ? 'u' : f->type;
		f->type = **line == 'x' ? 'x' : f->type;
		f->type = **line == 'X' ? 'X' : f->type;
		f->type = **line == '%' ? '%' : f->type;
		*line = *line + sizeof(char);
		print_arg(f);
	}
}

void	handle_length(char **line, t_f *f)
{
	handle_type(line, f);
}

void	handle_prec(char **line, t_f *f)
{
	if (**line == '.')
	{
		*line = *line + sizeof(char);
		if (**line == '*')
		{
			f->prec = va_arg(f->list, int);
			if (f->prec < 0)
				f->prec = 0;
			else if (f->prec == 0)
				f->prec = -2;
			*line = *line + sizeof(char);
		}
		else
		{
			f->prec = ft_atoi(*line) == 0 ? -2 : ft_atoi(*line);
			*line = next_field(*line);
		}
	}
	handle_length(line, f);
}

void	handle_width(char **line, t_f *f)
{
	if (ft_isdigit(**line) && **line != '0')
	{
		f->width = ft_atoi(*line);
		*line = next_field(*line);
	}
	else
	{
		if (**line == '*')
		{
			f->width = va_arg(f->list, int);
			if (f->width < 0)
			{
				f->width = -f->width;
				f->minus = 1;
			}
			*line = *line + sizeof(char);
		}
	}
	handle_prec(line , f);
}

void	handle_flags(char **line, t_f *f)
{
	while (ft_strchr("-0", **line))
	{
		zero(**line, f);
		minus(**line, f);
		*line = *line + sizeof(char);
	}
	if (f->return_v != -1)
		handle_width(line, f);
}
