# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = cub3d
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

HEADER      = cub3d.h
SRCS        = src/main.c \
			src/error_handler/error_msg.c \
			src/preprocess/parser.c \
			src/preprocess/input_validation.c \
			src/preprocess/parser_utils.c \
			src/preprocess/parser_data.c \
			src/preprocess/parser_map.c \
			src/preprocess/map_validation.c \
			src/preprocess/preprocess.c \
			src/preprocess/open_file.c \
			src/maths_utils/maths_utils_1.c \
			src/debug/logging.c \
			src/init_free/init_cub_1.c \
			src/init_free/init_cub_2.c \
			src/init_free/free_cub.c \
			src/init_free/utils_init_free.c \
			src/inputs_loop/inputs_loop.c \
			src/moves/position_moves.c \
			src/moves/vision_moves.c \

OBJS_DIR    = objs
OBJS        = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR   = ./lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_LINUX   = lib/mlx_linux/libmlx.a
MLX_MACOS   = lib/mlx_macos/libmlx.a

# Detect OS + Arch
UNAME_S     = $(shell uname -s)
UNAME_M     = $(shell uname -m)

ifeq ($(UNAME_S), Linux)
    INCLUDES = -Iincludes -Imlx_linux -Iincludes/linux_include -I$(LIBFT_DIR)
    MLX      = $(MLX_LINUX)
    LDFLAGS  = -Llib/mlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S), Darwin)
    INCLUDES = -Iincludes -Imlx_macos -Iincludes/macos_include -I$(LIBFT_DIR)
    MLX      = $(MLX_MACOS)
    LDFLAGS  = -Llib/mlx_macos -lmlx -framework OpenGL -framework AppKit
    # Cas spécial ARM (Mac M1/M2/M3)
    ifeq ($(UNAME_M), arm64)
        CFLAGS  += -arch arm64
        LDFLAGS += -arch arm64
    endif
else
    $(error Unsupported operating system: $(UNAME_S))
endif

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\n[Linking] $@"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $@
	@echo "[Done] Compilation complete!"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "[Compiling] $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(MLX_LINUX):
	@echo "[Building] MinilibX (Linux)"
	@make -s -C lib/mlx_linux

$(MLX_MACOS):
	@echo "[Building] MinilibX (macOS)"
	@make -s -C lib/mlx_macos

run: all
	./$(NAME) map1.cub

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR) >/dev/null
	@if [ -d mlx_linux ]; then make clean -C ./lib/mlx_linux >/dev/null; fi
	@if [ -d mlx_macos ]; then make clean -C ./lib/mlx_macos >/dev/null; fi
	@echo "[Clean] Object files removed"

fclean: clean
	@$(RM) $(NAME) *.out
	@make fclean -C $(LIBFT_DIR) >/dev/null
	@echo "[Clean] Executable removed"

re: fclean all

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re run leaks
