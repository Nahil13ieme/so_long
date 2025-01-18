NAME = so_long
SRC = $(addprefix src/, main.c game_logic.c texture.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Wextra -Wall -Werror

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

# Chemin vers les fichiers d'en-tête
INCLUDES = -Iincludes -Isrc

# All target
all: $(NAME)

# Link object files and libraries to create the final executable
$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	$(CC) $(CCFLAGS) $^ $(MLX_LIB) -L$(MLX_DIR) -lX11 -lXext -lm -o $(NAME)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

# Clean up all generated files, including the executable
fclean: clean
	rm -f $(NAME)

# Clean and rebuild everything
re: fclean all
