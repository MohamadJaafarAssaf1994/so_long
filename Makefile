NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR ?= minilibx-linux
ifeq ($(wildcard $(MLX_DIR)/mlx.h),)
$(error MiniLibX not found in $(MLX_DIR). Run make MLX_DIR=/path/to/minilibx-linux)
endif

CPPFLAGS = -I. -Ilibft -Ilibft/getNextLine -Ilibft/libftprintf -I$(MLX_DIR)
UNAME = $(shell uname)
MLX = $(MLX_DIR)/libmlx_$(UNAME).a
MLX_INC ?= /usr/include
MLX_BUILD_CC ?= gcc -std=gnu89
MLX_FLAGS = -lXext -lX11 -lm

SRCS = so_long.c \
	parse1.c \
	parse2.c \
	parsing_checkers1.c \
	parsing_checkers2.c \
	parsing_checkers_utils.c \
	parsing_checkers_utils_path.c \
	parsing_checkers_utils_walls.c \
	parsing_utils.c \
	so_long_utils.c \
	run_game.c \
	game_design.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk INC="$(MLX_INC)" CC="$(MLX_BUILD_CC)" all

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk clean

re: fclean all

.PHONY: all clean fclean re
