MAKEFLAGS += --no-print-directory

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -L $(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11

BUILD_PATH = build
CFILES_PATH = src
CFILES =	$(CFILES_PATH)/main.c \
			$(CFILES_PATH)/error_handler/error_msg.c \
			$(CFILES_PATH)/preprocess/parser.c \
			$(CFILES_PATH)/preprocess/preprocess.c \
			$(CFILES_PATH)/preprocess/open_file.c \
			$(CFILES_PATH)/debug/logging.c \
			$(CFILES_PATH)/init_free/init_cub_1.c \
			$(CFILES_PATH)/init_free/init_cub_2.c \
			$(CFILES_PATH)/init_free/free_cub.c \
			$(CFILES_PATH)/init_free/utils_init.c \
			$(CFILES_PATH)/loop/loop.c \
			$(CFILES_PATH)/user_input/vision_moves.c \
			$(CFILES_PATH)/user_input/position_moves.c \


LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = lib/mlx
MLX_LIB = $(MLX_PATH)/libmlx.a

OBJ = $(CFILES:$(CFILES_PATH)/%.c=$(BUILD_PATH)/%.o)

NAME = Cub3d

all:
	@echo "Building $(NAME)...\n"
	@$(MAKE) $(LIBFT)
	@$(MAKE) $(MLX_LIB)
	@$(MAKE) $(NAME)
	@echo "Done."

$(LIBFT):
	@echo "Building libft...\n"
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
	@echo "Building mlx...\n"
	@$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	@echo "Linking $(NAME)...\n"
	$(CC) $(OBJ) $(LIBFT) $(MLX_LIB) -lm $(MLXFLAGS) -o $(NAME)

$(BUILD_PATH)/%.o: $(CFILES_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@

clean:
	@echo "Cleaning object files...\n"
	@rm -f $(BUILD_PATH)/*.o
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	@echo "Fully cleaning project...\n"
	@rm -f $(NAME)
	@rm -rf $(BUILD_PATH)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
