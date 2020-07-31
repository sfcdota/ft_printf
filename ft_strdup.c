/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:55:20 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 16:43:26 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup(const char *s)
{
	unsigned char *t;

	t = malloc(ft_strlen(s) + 1);
	if (t)
		return (ft_memmove(t, s, ft_strlen(s) + 1));
	return (NULL);
}