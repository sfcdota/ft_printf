# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 23:22:49 by cbach             #+#    #+#              #
#    Updated: 2020/07/29 15:46:51 by cbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
HEAD =	libftprintf.h
FLAGS = -Wall -Wextra -Werror

SRC =						\

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
	$(MAKE) -C ./libft all
	$(MAKE) -C ./libft bonus
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
	$(MAKE) -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean


re: fclean all
