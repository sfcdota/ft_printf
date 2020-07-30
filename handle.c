/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:41:32 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 00:57:45 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*next_field(char *s)
{
	while (ft_isdigit(*s))
		s++;
	return (s);
}

int		print_arg(t_f *f)
{
	int len;

	len = 0;
	len = f->type == 'c' ? print_c(f) : len;
	len = f->type == 's' ? print_spxX(f) : len;
	len = f->type == 'p' ? print_spxX(f) : len;
	len = f->type == 'd' ? print_diu(f) : len;
	len = f->type == 'i' ? print_diu(f) : len;
	len = f->type == 'u' ? print_diu(f) : len;
	len = f->type == 'x' ? print_spxX(f) : len;
	len = f->type == 'X' ? print_spxX(f) : len;
	len = f->type == '%' ? print_c(f) : len;

	//printf("len after printarg =%d\n", len);
	return (len);
}

int		handle_type(char **line, t_f *f)
{
	if (!ft_strchr("cspdiuxX%%", **line))
		return (-1);
	f->type = **line ==  'c' ? 'c' : f->type;
	f->type = **line ==  's' ? 's' : f->type;
	f->type = **line ==  'p' ? 'p' : f->type;
	f->type = **line ==  'd' ? 'd' : f->type;
	f->type = **line ==  'i' ? 'i' : f->type;
	f->type = **line ==  'u' ? 'u' : f->type;
	f->type = **line ==  'x' ? 'x' : f->type;
	f->type = **line ==  'X' ? 'X' : f->type;
	f->type = **line ==  '%' ? '%' : f->type;
	*line = *line + sizeof(char);
	//printf("\nstep after handle_type: line = %s\t line char = %c\t f->type = %c\n", *line, **line, f->type);
	return (print_arg(f));
}

int		handle_length(char **line, t_f *f)
{
	return (handle_type(line, f));
}

int		handle_prec(char **line, t_f *f)
{
	if (**line == '.')
	{
		*line = *line + sizeof(char);
		if (**line == '*')
		{
			f->prec = va_arg(f->list, int);
			f->prec = f->prec < 0 ? 0 : f->prec;
			*line = *line + sizeof(char);
		}
		else
		{
			f->prec = ft_atoi(*line) == 0 ? -2 : ft_atoi(*line);
			*line = next_field(*line);
		}
	}
	//printf("\nstep after handle_prec: line = %s\t line char = %c\t f->prec = %c\n", *line, **line, f->prec);
	return (handle_length(line, f));
}

int		handle_width(char **line, t_f *f)
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
			f->width = f->width < 0 ? -f->width : f->width;
			*line = *line + sizeof(char);
		}
	}
	//printf("\nstep after handle_width: line = %s\t line char = %c\t f->width = %c\n", *line, **line, f->width);
	return (handle_prec(line, f));
}

int		handle_flags(char **line, t_f *f)
{
	while (ft_strchr("-0", **line))
	{
		if ((zero(**line, f) == -1) || (minus(**line, f) == -1))
			return (-1);
		*line = *line + sizeof(char);
	}
	//printf("\nstep after handle_flags: line = %s\t line char = %c", *line, **line);
	return (handle_width(line, f));
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
			//printf("\nstep before handle: temp = %d\t line = %s\t line char = %c", temp, line, *line);
			if ((temp = handle_flags(&line, discard_options(f))) == -1)
				return (-1);
			//printf("\nstep after handle: temp = %d\t line = %s\t line char = %c", temp, line, *line);
			len = temp != -1 ? len + temp : temp;
		}
	}
	return (len);
}
