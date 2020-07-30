# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 23:22:49 by cbach             #+#    #+#              #
#    Updated: 2020/07/30 16:39:59 by cbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
HEAD =	printf.h
FLAGS = -Wall -Wextra -Werror

SRC =						\
print_c.c					\
print_diu.c					\
print_spxX.c				\
flags.c						\
handle.c					\
utils.c						\
printf.c					\
ft_atoi.c					\
ft_isdigit.c				\
ft_memmove.c				\
ft_putchar_fd.c				\
ft_putnbr_fd.c				\
ft_putstr_fd.c				\
ft_strchr.c					\
ft_strdup.c					\
ft_strlen.c					\

BONUS =						\

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, %.o, $(BONUS))

ifdef BONUS_FILES
OBJ_FILES = $(OBJ_BONUS)
else
OBJ_FILES = $(OBJ)
endif

.PHONY: all bonus clean fclean re so

all: $(NAME)
	rm -f .depend

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $?

bonus:
	$(MAKE) BONUS_FILES=1 all

.depend: $(SRC) $(BONUS)
	rm -f .depend
	gcc $(FLAGS) -MM $^ > .depend;

-include .depend

%.o:
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS) .depend

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all

so: $(NAME_SO)

$(NAME_SO):
	gcc -c -fPIC *.c
	gcc -shared -o libft.so *.o
