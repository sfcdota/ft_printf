/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:57:53 by cbach             #+#    #+#             */
/*   Updated: 2020/07/29 19:14:51 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		minus(char c, t_format *format)
{
	if (c == '-')
	{
		if (format->flag_minus == 1)
			return (-1);
		format->flag_minus = 1;
		return (1);
	}
	return (0);
}

int		plus(char c, t_format *format)
{
	if (c == '+')
	{
		if (format->flag_plus == 1)
			return (-1);
		format->flag_plus = 1;
		return (1);
	}
	return (0);
}

int		zero(char c, t_format *format)
{
	if (c == '0')
	{
		if (format->flag_zero == 1)
			return (-1);
		format->flag_zero = 1;
		return (1);
	}
	return (0);
}

int		hash(char c, t_format *format)
{
	if (c == '-')
	{
		if (format->flag_hash == 1)
			return (-1);
		format->flag_hash = 1;
		return (1);
	}
	return (0);
}

int		space(char c, t_format *format)
{
	if (c == '-')
	{
		if (format->flag_space == 1)
			return (-1);
		format->flag_space = 1;
		return (1);
	}
	return (0);
}
