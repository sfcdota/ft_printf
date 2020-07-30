/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:58:59 by cbach             #+#    #+#             */
/*   Updated: 2020/07/31 00:44:34 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"
int main()
{
	//printf("%.*d\n", -22, -532);
	//printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c\n", '"', '!', '"', '#', '$', '%', '&');
	//unsigned long long int a = 2;
	//int status = ft_printf("%70p\n", &a);
	int status = ft_printf("%.0x", 0);
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
