# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 11:11:37 by cgaspart          #+#    #+#              #
#    Updated: 2019/04/28 07:14:08 by mgazel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SRC :=	src/main.c \
		src/utils.c \
		src/ft_decision.c \
		src/ft_up_keys.c \
		src/ft_left_keys.c \
		src/ft_down_keys.c \
		src/ft_right_keys.c \
		src/ft_generate.c \
		src/print.c \
		src/ft_catchsign.c \
		src/ft_menu.c \
		src/ft_lose.c \
		src/signal.c \
		src/utils2.c
OBJ :=  $(subst src/, objects/, $(SRC:.c=.o))
LIBFT := libft/libft.a
FLAGS := -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@printf "\n\e[1;35mCréation du binaire\e[0m - %-50s\n" $@
	@gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME) -l termcap -lncurses

objects/%.o: src/%.c
	@printf "\e[1;31mCréation des .o\e[0m - %-50s\r" $@
	@mkdir -p objects/
	@gcc $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft/

clean:
	@/bin/rm -rf objects/ && \
	make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME) && \
	make -C libft fclean && \
	rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re
