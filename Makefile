BUILD_PATH = build
CFILES_PATH = src
CFILES =	$(CFILES_PATH)/main.c \
			$(CFILES_PATH)/error_handler/error_msg.c \
			$(CFILES_PATH)/preprocess/parser.c \
			$(CFILES_PATH)/preprocess/input_validation.c \
			$(CFILES_PATH)/preprocess/parser_utils.c \
			$(CFILES_PATH)/preprocess/parser_data.c \
			$(CFILES_PATH)/preprocess/parser_map.c \
			$(CFILES_PATH)/preprocess/map_validation.c \
			$(CFILES_PATH)/preprocess/preprocess.c \
			$(CFILES_PATH)/preprocess/open_file.c \
			$(CFILES_PATH)/maths_utils/maths_utils_1.c \
			$(CFILES_PATH)/debug/logging.c \
			$(CFILES_PATH)/init_free/init_cub_1.c \
			$(CFILES_PATH)/init_free/init_cub_2.c \
			$(CFILES_PATH)/init_free/free_cub.c \
			$(CFILES_PATH)/init_free/utils_init_free.c \
			$(CFILES_PATH)/loop/loop.c \
			$(CFILES_PATH)/moves/position_moves.c \
			$(CFILES_PATH)/moves/vision_moves.c \
			$(CFILES_PATH)/map_rendering/calculate_fov.c \
			$(CFILES_PATH)/map_rendering/main_ray.c \
			$(CFILES_PATH)/minimap/minimap.c \



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
