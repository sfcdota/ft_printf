/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:41:32 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 14:35:13 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
int		print_arg(t_format *format)
{
	int len;

	len = 0;
	len = format->type == 'c' ? print_c(format) : len;
	// len = format->type == 's' ? print_s(format) : len;
	// len = format->type == 'p' ? print_p(format) : len;
	len = format->type == 'd' ? print_d(format) : len;
	len = format->type == 'i' ? print_d(format) : len;
	len = format->type == 'u' ? print_d(format) : len;
	// len = format->type == 'x' ? print_x(format) : len;
	// len = format->type == 'X' ? print_x(format) : len;

	//printf("len after printarg =%d\n", len);
	return (len);
}

int		handle_type(char **line, t_format *format)
{
	if (!ft_strchr("cspdiuxX", **line))
		return (-1);
	format->type = **line ==  'c' ? 'c' : format->type;
	format->type = **line ==  's' ? 's' : format->type;
	format->type = **line ==  'p' ? 'p' : format->type;
	format->type = **line ==  'd' ? 'd' : format->type;
	format->type = **line ==  'i' ? 'i' : format->type;
	format->type = **line ==  'u' ? 'u' : format->type;
	format->type = **line ==  'x' ? 'x' : format->type;
	format->type = **line ==  'X' ? 'X' : format->type;
	*line = *line + sizeof(char);
	//printf("\nstep after handle_type: line = %s\t line char = %c\t format->type = %c\n", *line, **line, format->type);
	return (print_arg(format));
}

int		handle_length(char **line, t_format *format)
{
	return (handle_type(line, format));
}

int		handle_precision(char **line, t_format *format)
{
	if (**line == '.')
	{
		*line = *line + sizeof(char);
		if (**line == '*')
			format->precision = -1;
		else
		{
			format->precision = ft_atoi(*line);
			*line += i_len(format->precision);
		}
	}
	//printf("\nstep after handle_precision: line = %s\t line char = %c\t format->precision = %c\n", *line, **line, format->precision);
	return (handle_length(line, format));
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
		{
			format->width = -1;
			*line = *line + sizeof(char);
		}
	}
	//printf("\nstep after handle_width: line = %s\t line char = %c\t format->width = %c\n", *line, **line, format->width);
	return (handle_precision(line, format));
}

int		handle_flags(char **line, t_format *format)
{
	while (ft_strchr("-0", **line))
	{
		if ((zero(**line, format) == -1) || (minus(**line, format) == -1))
			return (-1);
		*line = *line + sizeof(char);
	}
	//printf("\nstep after handle_flags: line = %s\t line char = %c", *line, **line);
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
				//printf("\nstep before handle: temp = %d\t line = %s\t line char = %c", temp, line, *line);
				if ((temp = handle_flags(&line, discard_options(format))) == -1)
					return (-1);
				//printf("\nstep after handle: temp = %d\t line = %s\t line char = %c", temp, line, *line);
				len = temp != -1 ? len + temp : temp;
			}
		}
	}
	return (len);
}
