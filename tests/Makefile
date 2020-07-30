# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 13:44:31 by cbach             #+#    #+#              #
#    Updated: 2020/07/30 12:06:27 by cbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -g3 -Wall -Wextra -Werror

all: clear compile run clear

compile:
	@ $(MAKE) -C ../libft/ all
	@ $(MAKE) -C ../libft/ bonus
	@ gcc $(FLAGS) ../*.c ../libft/libft.a main.c -o f

run:
	@ valgrind --leak-check=yes -v -s ./f
	@ echo
	@ ./f | cat -e

clear:
	@ -rm -f
	@ $(MAKE) -C ../libft fclean
main:
	@ gcc $(FLAGS) main.c ../print_c.c ../print_d.c ../utils.c ../printf.c
	../flags.c ../handle.c -o f
	@ ./f | cat -e
	@ -rm -f
