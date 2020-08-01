/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:58:59 by cbach             #+#    #+#             */
/*   Updated: 2020/08/01 16:24:13 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"
int main()
{
	ft_printf("status = %d\n\n\n", ft_printf("%5"));
	//printf("status = %d\n\n\n", printf("or = %-5"));
	//printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c\n", '"', '!', '"', '#', '$', '%', '&');
	//unsigned long long int a = 2;
	//int status = ft_printf("%70p\n", &a);
	return (0);
}

//			%c
// flags: only - allowed
// prec not allowed
//length: only l allowed

//			%diu
// '0' игнорится если есть '-'
// ' ' игнорится если есть '+'


//			%xX
// flags: ' ' and '+' not allowed
// '0' игнорится если есть '-'
//
