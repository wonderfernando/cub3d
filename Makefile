# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:40:26 by ferda-si          #+#    #+#              #
#    Updated: 2024/11/08 17:50:28 by ferda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/main.c src/verify_params.c src/verify_interior.c src/get_next_line.c src/get_next_line_utils.c src/utils.c src/valide_map.c

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