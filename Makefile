# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brdany <brdany@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 18:10:28 by tbraud            #+#    #+#              #
#    Updated: 2025/07/12 17:11:18 by brdany           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long

SRC_DIR	:= src
OBJ_DIR	:= obj

CC		:= cc
CFLAGS	:= -g -Wextra -Wall -Werror

INCLUDE	:= -I ./include

SRC		:= main.c \
			get_next_line_utils.c \
			get_next_line.c \
			insert_map.c \
			keyboard_key.c \
			keyboard_key_utils.c \
			parsing.c \
			parsing_two.c \
			error.c
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN	:= \033[1;32m
NC		:= \033[0m

LIB 	:= make -sC mlx
LIB.A	:= mlx/libmlx_Linux.a

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB)
	@$(CC) $(OBJ) $(LIB.A) -lXext -lX11 -lm -lz -o $(NAME) && printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make clean -sC $(MLX_PATH)
	@echo "\033[1;32mDone\n"

re: clean all

.PHONY: all clean fclean re
