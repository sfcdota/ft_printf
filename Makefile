# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 23:22:49 by cbach             #+#    #+#              #
#    Updated: 2020/07/31 14:18:24 by cbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
HEAD =	printf.h
FLAGS = -Wall -Wextra -Werror

SRC =						\
flags.c						\
handle_fields.c				\
libft_utils.c				\
libft_utils2.c				\
print_cspxx.c				\
print_diu.c					\
printf.c					\
utils.c						\


BONUS =						\

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, %.o, $(BONUS))

ifdef BONUS_FILES
OBJ_FILES = $(OBJ_BONUS)
else
OBJ_FILES = $(OBJ)
endif

.PHONY: all bonus clean fclean re

all: $(NAME)
	@ rm -f .depend

$(NAME): $(OBJ_FILES)
	@ ar -rcs $(NAME) $?

bonus:
	$(MAKE) BONUS_FILES=1 all

.depend: $(SRC) $(BONUS)
	@ rm -f .depend
	@ gcc $(FLAGS) -MM $^ > .depend;

-include .depend

%.o:
	@ gcc $(FLAGS) -c $< -o $@

clean:
	@ rm -f $(OBJ) $(OBJ_BONUS) .depend

fclean: clean
	@ rm -f $(NAME)

re: fclean all
