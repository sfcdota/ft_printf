/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:52:31 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 14:16:34 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static int	is_over(long long int i, int multiplier, int current)
{
	if ((i == 922337203685477580 && current > 54 && multiplier == 1)
	|| (i == 922337203685477580 && current > 55 && multiplier == -1)
	|| i > 922337203685477580)
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *nptr)
{
	long long int	i;
	int				multiplier;

	i = 0;
	multiplier = 1;
	while ((*nptr > 6 && *nptr < 14) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			multiplier *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (is_over(i, multiplier, *nptr))
			return (multiplier == 1 ? -1 : 0);
		i = i * 10 + (*nptr++ - 48);
	}
	return (i * multiplier);
}

int			ft_isdigit(int c)
{
	return (c > 47 && c < 58 ? 1 : 0);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (n && (dest || src))
	{
		i = 0;
		d = (char *)dest;
		s = (char *)src;
		if (dest < src)
			while (i++ < n)
				*(d++) = *(s++);
		else
			while (i++ < n)
				*(d + n - i) = *(s + n - i);
	}
	return (dest);
}

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
