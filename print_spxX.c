/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:48:13 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 01:47:53 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr_fd_l(char *s, int fd, size_t len)
{
	while (s && *s && len--)
		ft_putchar_fd(*s++, fd);
}


char	*ft_itoa_16(unsigned long long n, t_f *f)
{
	char				*output;
	int					len;
	char				*base16;

	if (n == 0 && f->type == 'p')
		return (NULL);
	len = i16_len(n);
	base16 = f->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	f->hash = f->type == 'p' ? 1 : 0;
	if (!(output = malloc(len + 1 + (f->hash ? 2 : 0))))
		return (NULL);
	if (f->hash)
	{
		output[1] = f->type == 'X' ? 'X' : 'x';
		output[0] = '0';
	}
	output[len + (f->hash ? 2 : 0)] = '\0';
	while (n >= 16)
	{
		output[--len + (f->hash ? 2 : 0)] = base16[n % 16];
		n /= 16;
	}
	output[--len + (f->hash ? 2 : 0)] = base16[n % 16];
	return (output);
}

void	put_triplet_pxX(char *s, int len, char filler, t_f *f)
{
	int is_num;

	//printf("info : s = %s\t len = %d\t filler = %c\n", s, len, filler);
	if (f->width > f->prec + len && f->zero && f->prec)
	{
		f->zero = 0;
		filler = ' ';
	}
	is_num = ft_strchr("xX", f->type) ? 1 : 0;
	if (f->minus)
	{
		if (f->prec > len)
			fill(f->prec - len, is_num ? '0' : ' ');
		if (f->prec != -2)
			ft_putstr_fd_l(s, 1, len);
		if (f->width > f->prec + len)
			fill(f->width - max(f->prec, len, 0), filler);
	}
	else
	{
		if (f->width > f->prec + len)
			fill(f->width - max(f->prec, len, 0), filler);
		if (f->prec > len)
			fill(f->prec - len, is_num ? '0' : ' ');
		if (f->prec != -2)
			ft_putstr_fd_l(s, 1, len);
	}

}

int		adjust_spxX(char *s, t_f *f)
{
	char	filler;
	int		len;

	len = ft_strlen(s);
	f->zero = f->minus ? 0 : f->zero;
	filler = f->zero ? '0' : ' ';
	len = f->prec == -2 ? 0 : len;
	if (f->type == 's')
	{
		len = f->prec > 0 && f->prec < len ? f->prec : len;
		f->minus ? ft_putstr_fd_l(s, 1, len) : fill(max(0, f->width, len) - len, filler);
		f->minus ? fill(max(0, f->width, len) - len, filler) : ft_putstr_fd_l(s, 1, len);
		return (max(0, len, f->width));
	}
	else
	{
		put_triplet_pxX(s, len, filler, f);
		return (max(f->prec, f->width, len));
	}
}

int	print_spxX(t_f *f)
{
	char	*str;
	int		status;
	int		need_free;

	str = f->type == 's' ? va_arg(f->list, char *) : ft_itoa_16((unsigned long long int)va_arg(f->list, void *), f);
	need_free = str == NULL || f->type != 's' ? 1 : 0;
	if (str == NULL)
	{
		if (f->type == 's')
			str = f->prec < (int)ft_strlen("(null)") && f->prec > 0 ? ft_strdup("") : ft_strdup("(null)");
		else if (f->type == 'p')
			str = f->prec < (int)ft_strlen("(nil)") && f->prec > 0 ? ft_strdup("") : ft_strdup("(nil)");
		else
			str = ft_strdup("");
	}
	status = adjust_spxX(str, f);
	if (need_free)
		free(str);
	return (status);
}
