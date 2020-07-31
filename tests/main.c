/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:58:59 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 12:09:42 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"
int main()
{
	printf("orig = %.*o\n", -3, 12345);
	//printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c\n", '"', '!', '"', '#', '$', '%', '&');
	//unsigned long long int a = 2;
	//int status = ft_printf("%70p\n", &a);
	int status = ft_printf("my = %.*o\n", -3, 12345);
	printf("\nstatus = %d\n", status);
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
