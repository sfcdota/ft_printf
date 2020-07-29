/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:25:44 by cbach             #+#    #+#             */
/*   Updated: 2020/07/29 18:39:27 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *line, ...)
{
	int status;

	if (!line)
		return (-1);
	t_format	format;
	va_start(discard_options(&format)->list, line);
	status = handle(line, &format);
	va_end(format.list);
	return (status != -1 ? format.length : status);
}
