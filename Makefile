NAME = so_long
SRC = $(addprefix src/, main.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Wextra -Wall -Werror

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	$(CC) $(CCFLAGS) $^ $(MLX_LIB) -L$(MLX_DIR) -lX11 -lXext -lm -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I$(MLX_DIR) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
