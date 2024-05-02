# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:07:18 by brulutaj          #+#    #+#              #
#    Updated: 2024/05/02 17:29:51 by brulutaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
HEADERS = ./Libft/Headers
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADERS)
RM = rm -f

LIBFT_MAKE = ./Libft

SRC =   main.c 		\
		swap.c 		\
		push.c 		\
		rotate.c 	\
		r-rotate.c 	\
		utils_1.c 	\
		utils_2.c 	\
		parsing.c 	\
		move_calc.c	\
		mini_sort.c	\
		lis_sort.c	\
		finalization.c

SRC_BONUS =		swap.c 						\
				push.c 						\
				rotate.c 					\
				r-rotate.c 					\
				utils_1.c 					\
				utils_2.c 					\
				parsing.c 					\
				move_calc.c					\
				mini_sort.c					\
				lis_sort.c					\
				finalization.c				\
				./bonus/check_main_bonus.c	\
				./bonus/check_pars_bonus.c	\
				./bonus/push_bonus.c		\
				./bonus/r-rotate_bonus.c	\
				./bonus/rotate_bonus.c		\
				./bonus/swap_bonus.c				

all: $(NAME)

$(NAME): $(SRC)
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(FLAGS) -I. -I$(HEADERS) $(SRC) -L$(LIBFT_MAKE) -lft -o $(NAME)

bonus: $(SRC_BONUS)
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(FLAGS) -I. -I$(HEADERS) $(SRC_BONUS) -L$(LIBFT_MAKE) -lft -o $(NAME_BONUS)

clean:
	@make clean -s -C $(LIBFT_MAKE)

fclean: clean
	@make fclean -s -C $(LIBFT_MAKE)
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

# .SILENT:
.PHONY: all clean fclean re