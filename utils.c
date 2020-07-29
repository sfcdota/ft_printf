/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:38:44 by cbach             #+#    #+#             */
/*   Updated: 2020/07/29 23:46:18 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_format	*discard_options(t_format *format)
{
	format->flag_minus = 0;
	format->flag_plus = 0;
	format->flag_space = 0;
	format->flag_zero = 0;
	format->flag_hash = 0;
	format->width = 0;
	format->precision = 0;
	format->length = 0;
	format->type = 0;
	return (format);
}

int			i_len(long long int i)
{
	int len;

	len = 1;
	while (i > 10)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int			ui_len(unsigned long long int i)
{
	int len;

	len = 1;
	while (i > 10)
	{
		i /= 10;
		len++;
	}
	return (len);
}
