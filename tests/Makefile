# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 13:44:31 by cbach             #+#    #+#              #
#    Updated: 2020/08/01 21:18:02 by cbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

all: clear compile run clear

compile:
	@ gcc $(FLAGS) ../*.c ../libft/libft.a main.c -o f

run:
	@ valgrind --leak-check=yes -v -s ./f
	@ echo
	@ ./f | cat -e

clear:
	@ -rm -f
main:
	@ -rm -f
	@ gcc $(FLAGS) main.c ../*.c -o f
	@ ./f | cat -e
	@ -rm -f
mainv: main
	@ valgrind --leak-check=yes -v -s ./f
#	ДЛЯ ПОДРУБКИ ЛИБЫ, НАДО В GCC В САМОМ КОНЦЕ (ПЕРЕД -о ) НАПИСАТЬ -L../libft -lft
