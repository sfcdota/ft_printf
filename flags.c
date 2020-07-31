/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:57:53 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 14:16:12 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		minus(char c, t_f *f)
{
	if (c == '-')
	{
		if (f->minus == 1)
			return (-1);
		f->minus = 1;
		return (1);
	}
	return (0);
}

int		zero(char c, t_f *f)
{
	if (c == '0')
	{
		if (f->zero == 1)
			return (-1);
		f->zero = 1;
		return (1);
	}
	return (0);
}
