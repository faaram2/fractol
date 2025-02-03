# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayeganya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 11:05:36 by ayeganya          #+#    #+#              #
#    Updated: 2024/06/06 15:49:28 by ayeganya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler CFLAGS
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

# Header files
H_FILE = fractol.h

#Source files
SRC_FILES = fractol.c utils.c algorithms.c
#B_SRC_FILES = 

OBJ_FILES = $(SRC_FILES:%.c=%.o)

#Libft
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

#Mini_Libx
MINI_LIBX_DIR = ./minilibx
MINI_LIBX_A = $(MINI_LIBX_DIR)/libmlx.a

#Target
NAME  = fractol
BONUS = fractol

all: $(LIBFT_A) $(MINI_LIBX_A) $(NAME)

$(NAME): $(OBJ_FILES) $(H_FILE)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) $(MINI_LIBX_A) -lm -framework OpenGL -framework AppKit -o $@

#Object target
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#Libft target
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

#Minilibx target
$(MINI_LIBX_A):
	$(MAKE) -C $(MINI_LIBX_DIR)


bonus: $(LIBFT_A) $(MINI_LIBX_A) $(NAME) 

#cleaning targets
clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINI_LIBX_DIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean	
	$(MAKE) -C $(MINI_LIBX_DIR) fclean

re: fclean all

lclean:
	rm -f $(OBJ_FILES)

rf: lclean $(NAME)

.PHONY: all clean fclean re rf lclean

