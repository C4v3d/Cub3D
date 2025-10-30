MAKEFLAGS += --no-print-directory

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD_PATH = build
CFILES_PATH = src
CFILES =	$(CFILES_PATH)/main.c \
			$(CFILES_PATH)/debug/logging.c \
			$(CFILES_PATH)/error_handler/error_msg.c \
			$(CFILES_PATH)/game_rendering/game_rendering.c \
			$(CFILES_PATH)/game_rendering/loop.c \
			$(CFILES_PATH)/game_rendering/rendering_utils_1.c \
			$(CFILES_PATH)/game_rendering/rays_calculation.c \
			$(CFILES_PATH)/game_rendering/rays_cal_utils.c \
			$(CFILES_PATH)/init_free/init_cub_1.c \
			$(CFILES_PATH)/init_free/init_cub_2.c \
			$(CFILES_PATH)/init_free/free_cub.c \
			$(CFILES_PATH)/maths_utils/maths_utils_1.c \
			$(CFILES_PATH)/minimap/mark_minimap.c \
			$(CFILES_PATH)/minimap/minimap_rendering.c \
			$(CFILES_PATH)/moves/position_moves.c \
			$(CFILES_PATH)/moves/vision_moves.c \
			$(CFILES_PATH)/preprocess/parser.c \
			$(CFILES_PATH)/preprocess/input_validation.c \
			$(CFILES_PATH)/preprocess/parser_utils.c \
			$(CFILES_PATH)/preprocess/parser_data.c \
			$(CFILES_PATH)/preprocess/parser_map.c \
			$(CFILES_PATH)/preprocess/map_validation.c \
			$(CFILES_PATH)/preprocess/preprocess.c \
			$(CFILES_PATH)/preprocess/open_file.c \


LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_LINUX = lib/mlx_linux/libmlx.a
MLX_MACOS = lib/mlx_macos/libmlx.a
OBJ = $(CFILES:$(CFILES_PATH)/%.c=$(BUILD_PATH)/%.o)

UNAME_S = $(shell uname -s)
UNAME_M = $(shell uname -m)

ifeq ($(UNAME_S), Linux)
	INCLUDES = -Iincludes -Imlx_linux -Iincludes/linux_include -I$(LIBFT_PATH)
	MLX = $(MLX_LINUX)
	LDFLAGS = -Llib/mlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S), Darwin)
	INCLUDES = -Iincludes -Imlx_macos -Iincludes/macos_include -I$(LIBFT_PATH)
	MLX = $(MLX_MACOS)
	LDFLAGS = -Llib/mlx_macos -lmlx -framework OpenGL -framework AppKit
	ifeq ($(UNAME_M), arm64)
		CFLAGS += -arch arm64
		LDFLAGS += -arch arm64
	endif
else
	$(error Unsupported operating system: $(UNAME_S))
endif

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "\n[Linking] $@"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $@
	@echo "[Done] Compilation complete!"

$(BUILD_PATH)/%.o: $(CFILES_PATH)/%.c
	@mkdir -p $(dir $@)
	@echo "[Compiling] $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

ifeq ($(UNAME_S), Linux)

$(MLX):
	@echo "[Building] MinilibX (Linux)"
	@make -s -C lib/mlx_linux

else ifeq ($(UNAME_S), Darwin)

$(MLX):
	@echo "[Building] MinilibX (macOS)"
	@make -s -C lib/mlx_macos

endif

clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT_PATH) >/dev/null

ifeq ($(UNAME_S), Linux)

	@if [ -d lib/mlx_linux ]; then make clean -C lib/mlx_linux >/dev/null; fi

else ifeq ($(UNAME_S), Darwin)

	@if [ -d lib/mlx_macos ]; then make clean -C lib/mlx_macos >/dev/null; fi

endif

	@echo "[Clean] Object files removed"

fclean: clean
	@$(RM) $(NAME) *.out
	@make fclean -C $(LIBFT_PATH) >/dev/null
	@echo "[Clean] Executable removed"

re: fclean all

run: all
	./$(NAME) map2.cub

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re run leaks
