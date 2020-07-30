/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:57:53 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 14:36:37 by cbach            ###   ########.fr       */
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
