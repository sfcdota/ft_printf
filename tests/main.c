/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:58:59 by cbach             #+#    #+#             */
/*   Updated: 2020/07/30 14:37:24 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"
int main()
{
	//printf("%#15x\n", 22832213);
	//printf("%-5c\n", 'a');
	int status = ft_printf("%d\n", 228);
	printf("\nstatus = %d\n", status);
	return (0);
}

//			%c
// flags: only - allowed
// precision not allowed
//length: only l allowed



//			%diu
// '0' игнорится если есть '-'
// ' ' игнорится если есть '+'


//			%xX
// flags: ' ' and '+' not allowed
// '0' игнорится если есть '-'
//
