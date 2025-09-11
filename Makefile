MAKEFLAGS += --no-print-directory

CC = cc
CFLAGS = -Wall -Werror -Wextra

BUILD_PATH = build
CFILES_PATH = src
CFILES =	$(CFILES_PATH)/main.c \
			$(CFILES_PATH)/error_handler/error_msg.c \

LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJ = $(CFILES:$(CFILES_PATH)/%.c=$(BUILD_PATH)/%.o)

NAME = Cub3d

all:
	@echo "Building $(NAME)...\n"
	@$(MAKE) $(LIBFT)
	@$(MAKE) $(NAME)
	@echo "Done."

$(LIBFT):
	@echo "Building libft...\n"
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Linking $(NAME)...\n"
	@$(CC) $(OBJ) $(LIBFT) -lm -o $(NAME)

$(BUILD_PATH)/%.o: $(CFILES_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files...\n"
	@rm -f $(BUILD_PATH)/*.o
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@echo "Fully cleaning project...\n"
	@rm -f $(NAME)
	@rm -rf $(BUILD_PATH)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re