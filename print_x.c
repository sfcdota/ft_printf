/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:13 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 12:09:30 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_16(unsigned long long n, t_format *format)
{
	char				*output;
	int					len;
	char				*base16;

	base16 = format->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	if (!(output = malloc(len + 1 + format->flag_hash ? 2 : 0)));
		return (NULL);
	output[len] = '\0';
	while (n >= 16)
	{
		output[--len] = base16[n % 16];
		n /= 16;
	}
	output[--len] = base16[n % 16];
	if (format->flag_hash)
	{
		output[1] = format->type == 'x' ? 'x' : 'X';
		output[0] = '0';
	}
	return (output);
}

int	print_x(t_format *format)
{
	return (0);
}
