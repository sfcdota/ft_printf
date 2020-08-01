/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:53:36 by cbach             #+#    #+#             */
/*   Updated: 2020/08/01 23:38:15 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbrll_fd(long long int n, int fd, t_f *f)
{
	if (n == -9223372036854775807LL - 1LL)
		ft_putstr_fd_l("−9223372036854775808", fd, 20, f);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd, f);
			n *= -1;
		}
		if (n > 9)
			ft_putnbrll_fd(n / 10, fd, f);
		ft_putchar_fd(n % 10 + 48, fd, f);
	}
}

void	ft_putstr_fd_l(char *s, int fd, size_t len, t_f *f)
{
	while (s && *s && len--)
		ft_putchar_fd(*s++, fd, f);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return (*s == c ? (char *)s : NULL);
}

char	*ft_strdup(const char *s)
{
	unsigned char *t;

	t = malloc(ft_strlen(s) + 1);
	if (t)
		return (ft_memmove(t, s, ft_strlen(s) + 1));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
