# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:40:26 by ferda-si          #+#    #+#              #
#    Updated: 2025/05/21 17:18:50 by ferda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/check_map.c \
		src/get_next_line.c \
        src/get_next_line_utils.c \
		src/main.c \
        src/verify_params.c \
        src/verify_interior.c \
        src/utils.c \
        src/valide_map.c \
        src/utils_two.c \
        src/utils_validate.c \
		src/utils_map_three.c \
		src/utils_four.c \
		src/utils_five.c \


OBJS = $(FILES:src/%.c=objs/%.o)

CFLAGS          = -Wall -Werror -Wextra
NAME = cub3d

LIBFT = ./libft/libft.a

OBJS_PATH = objs/
FILES_PATH = src/

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C ./libft
	cc $(CFLAGS) -I headers $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_PATH)%.o: $(FILES_PATH)%.c
	@mkdir -p objs
	cc $(CFLAGS) -I headers -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_PATH)
	@$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS_PATH)
	@$(MAKE) fclean -C ./libft

re: fclean clean all