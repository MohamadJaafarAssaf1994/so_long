NAME = so_long
NAME_BONUS = so_long_bonus

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

COMMON_SRCS = so_long.c \
	parse1.c \
	parse2.c \
	parsing_checkers1.c \
	parsing_checkers2.c \
	parsing_checkers_utils.c \
	parsing_checkers_utils_path.c \
	parsing_checkers_utils_walls.c \
	parsing_utils_1.c \
	parsing_utils_2.c \
	so_long_utils.c

MANDATORY_SRCS = $(COMMON_SRCS) \
	run_game_1.c \
	run_game_2.c \
	game_design.c

BONUS_SRCS = $(COMMON_SRCS) \
	run_game_1_bonus.c \
	run_game_2_bonus.c \
	game_design_bonus.c

OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk INC="$(MLX_INC)" CC="$(MLX_BUILD_CC)" all

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk clean

re: fclean all

.PHONY: all bonus clean fclean re
