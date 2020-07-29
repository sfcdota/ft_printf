/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:41:32 by cbach             #+#    #+#             */
/*   Updated: 2020/07/29 21:27:39 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_arg(t_format *format)
{
	int len;

	len = 0;
	len = format->type == 'c' ? print_c(format) : len;
	len = format->type == 's' ? print_s(format) : len;
	len = format->type == 'p' ? print_p(format) : len;
	len = format->type == 'd' ? print_d(format) : len;
	len = format->type == 'i' ? print_d(format) : len;
	len = format->type == 'u' ? print_d(format) : len;
	len = format->type == 'x' ? print_x(format) : len;
	len = format->type == 'X' ? print_x(format) : len;
	len = format->type == 'n' ? print_n(format) : len;
	len = format->type == 'f' ? print_f(format) : len;
	len = format->type == 'g' ? print_g(format) : len;
	len = format->type == 'e' ? print_e(format) : len;
	return (len);
}

int		handle_type(char **line, t_format *format)
{
	if (!ft_strchr(TYPES, **line))
		return (-1);
	format->type = **line ==  'c' ? 'c' : format->type;
	format->type = **line ==  's' ? 's' : format->type;
	format->type = **line ==  'p' ? 'p' : format->type;
	format->type = **line ==  'd' ? 'd' : format->type;
	format->type = **line ==  'i' ? 'i' : format->type;
	format->type = **line ==  'u' ? 'u' : format->type;
	format->type = **line ==  'x' ? 'x' : format->type;
	format->type = **line ==  'X' ? 'X' : format->type;
	format->type = **line ==  'n' ? 'n' : format->type;
	format->type = **line ==  'f' ? 'f' : format->type;
	format->type = **line ==  'g' ? 'g' : format->type;
	format->type = **line ==  'e' ? 'e' : format->type;
	*line++;
	return (print_arg(format));
}

int		handle_length(char **line, t_format *format)
{
	if (**line == 'l')
	{
		if (++(*line) == 'l')
			format->length = 'a';
		else
		{
			format->length = 'l';
			*line--;
		}
	}
	else
	{
		if (**line == 'h')
		{
			if (++(*line) == 'h')
				format->length = 'b';
			else
			{
				format->length = 'h';
				*line--;
			}
		}
	}
	return (handle_type(line, format));
}

int		handle_precision(char **line, t_format *format)
{
	if (**line == '.')
	{
		*line++;
		if (**line == '*')
			format->precision = -1;
		else
		{
			format->precision = ft_atoi(*line);
			*line += i_len(format->precision);
		}
	}
	return
}

int		handle_width(char **line, t_format *format)
{
	if (ft_isdigit(**line) && **line != '0')
	{
		format->width = ft_atoi(*line);
		*line += i_len(format->width);
	}
	else
	{
		if (**line == '*')
			format->width = -1;
		*line++;
	}
	return (handle_precision(line, format));
}

int		handle_flags(char **line, t_format *format)
{
	while (ft_strchr(FLAGS, **line))
	{
		if ((zero(**line, format) == -1) || (minus(**line, format) == -1) ||
		(plus(**line, format) == -1) || (hash(**line, format) == -1) ||
		(space(**line, format) == -1))
			return (-1);
		*line++;
	}
	return (handle_width(line, format));
}

int		handle(char *line, t_format *format)
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
			if (*line == '%')
			{
				ft_putchar_fd(*line++, 1);
				len++;
			}
			else
			{
				if ((temp = handle_flags(&line, discard_options(format)) == -1))
					return (-1);
				len = temp != -1 ? len + temp : temp;
			}
		}
	}
	return (len);
}
