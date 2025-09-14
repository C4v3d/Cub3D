MAKEFLAGS += --no-print-directory

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS	=	-L $(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11

BUILD_PATH = build
CFILES_PATH = src
CFILES =	$(CFILES_PATH)/main.c \
			$(CFILES_PATH)/error_handler/error_msg.c \
			$(CFILES_PATH)/validator/validate_map.c \

LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH		=	lib/mlx
MLX_LIB		=	$(MLX_PATH)/libmlx_Linux.a

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

$(NAME): $(OBJ) $(LIBFT)
	@echo "Linking $(NAME)...\n"
	@$(CC) $(OBJ) $(LIBFT) $(MLX_LIB) -lm -o $(NAME)

$(BUILD_PATH)/%.o: $(CFILES_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

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
