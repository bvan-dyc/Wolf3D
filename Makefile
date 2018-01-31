#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 22:53:24 by bvan-dyc          #+#    #+#              #
#    Updated: 2017/01/28 15:59:59 by bvan-dyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=wolf3d

CFLAGS=-Wall -Wextra -Werror

SRC=src/main.c src/raycast.c src/keyhook.c src/tools.c src/matrice.c \
src/display.c src/palettes.c src/music.c

OBJS=obj/main.o obj/raycast.o obj/keyhook.o obj/tools.o obj/matrice.o \
obj/display.o obj/palettes.o obj/music.o

$(NAME): $(OBJS)
	@printf "\n"
	@make -C libft/
	@gcc $(CFLAGS) -I /usr/X11/include -L libft/ -lft -l mlx \
	-framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	@printf '\033[32m -> %s\n\033[0m' "Wolf3d Compiled!"

obj/%.o: src/%.c
	@mkdir -p obj
	@gcc $(CFLAGS) -I /usr/X11/include -c $< -o $@
	@printf '\033[0m[/] %s\n\033[0m' "$<"

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)
	@printf '\033[0m[/] %s\n\033[0m' "cleaned Wolf3d"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME) rm -rf $(OBJS)
	@printf '\033[0m[/] %s\n\033[0m' "fcleaned Wolf3d"
	@printf "\n"

re: fclean all

.PHONY: clean fclean
