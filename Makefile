# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 20:03:40 by igrousso          #+#    #+#              #
#    Updated: 2025/01/24 18:44:10 by igrousso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# Project names

NAME = pipex
BONUS_NAME = 

# Source files

SRCS = $(addprefix sources/, utils.c)
MAIN = $(addprefix sources/, main.c)

SRCS_B = $(addprefix sources/bonus/, )
MAIN_B = $(addprefix sources/bonus/, main_bonus.c)

# Object files

OBJ =  $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)
OBJ_MAIN		=	$(MAIN:.c=.o)
OBJ_MAIN_B		=	$(MAIN_B:.c=.o)

ALL_OBJS		=	$(OBJ) $(OBJ_B) $(OBJ_MAIN) $(OBJ_MAIN_B)

# Library path

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Default target

all: $(NAME)

# Build the main program

$(NAME): $(OBJ) $(OBJ_MAIN) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

# Build the bonus program

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ_B) $(OBJ) $(OBJ_MAIN_B) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

# Compile library

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Generic rule for .c to .o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files

clean:
	rm -rf $(ALL_OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

# Full clean

fclean: clean
		rm -f $(NAME) $(BONUS_NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean

# Rebuild everything

re: fclean all

# Rebuild with bonus

rb: re bonus

# Phony targets

.PHONY : all clean fclean re bonus rb