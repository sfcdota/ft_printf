# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 13:44:31 by cbach             #+#    #+#              #
#    Updated: 2020/07/30 16:38:33 by cbach            ###   ########.fr        #
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
	@ -rm -f
	@ gcc $(FLAGS) main.c ../*.c -o f
	@ ./f | cat -e
	@ -rm -f

#	ДЛЯ ПОДРУБКИ ЛИБЫ, НАДО В GCC В САМОМ КОНЦЕ (ПЕРЕД -о ) НАПИСАТЬ -L../libft -lft
