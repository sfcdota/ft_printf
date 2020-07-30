/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:25:44 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 00:47:56 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *line, ...)
{
	int status;

	if (!line)
		return (-1);
	t_f	f;
	va_start(discard_options(&f)->list, line);
	status = handle((char *)line, &f);
	va_end(f.list);
	return (status);
}
