/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:51:35 by cbach             #+#    #+#             */
/*   Updated: 2020/07/28 17:46:35 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_16(unsigned long long n, int lowercase)
{
	char				*output;
	int					len;
	unsigned long long	temp;
	char				*base16;

	base16 = lowercase ? "0123456789abcdef" : "0123456789ABCDEF";
	len = 1;
	temp = n;
	while (temp >= 16)
	{
		len++;
		temp /= 16;
	}
	if (!(output = malloc(len + 1)))
		return (NULL);
	output[len] = '\0';
	while (n >= 16)
	{
		output[--len] = base16[n % 16];
		n /= 16;
	}
	output[--len] = base16[n % 16];
	return (output);
}
