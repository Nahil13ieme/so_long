NAME = game_test

SRC = $(addprefix src/, main.c game.c player.c level.c entity.c errors.c utils.c enemy.c render.c sprite.c)
GNL_SRC = $(addprefix gnl_bonus/, get_next_line.c get_next_line_utils.c)
OBJ = $(SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

INCLUDES = -Iinc -Isrc -I$(LIBFT_DIR)

all: $(NAME)

$(NAME) : $(OBJ) $(GNL_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT_LIB) $(MLX_LIB) -L$(MLX_DIR) -lX11 -lXext -lm -g -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -g -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(GNL_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all