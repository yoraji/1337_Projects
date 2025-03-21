NAME = so_long
CC = cc
MLX_PATH = /usr/include/minilibx-linux/
CFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH) -I./get_next_line
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11
GNL_PATH = ./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c
PRINTF_PATH = printf/ft_hexdecimal.c printf/ft_point.c printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putstr.c printf/ft_unsigned.c
SRCS =	src/main.c src/flood_fill.c src/left_right.c src/up_down.c src/strncpy.c \
		src/update_player_pos.c src/for_free.c src/handling_map.c src/ft_strlen.c \
		./src/path_utils.c ./src/ft_memcpy.c ./src/mlx.c src/utils_1.c src/utils_2.c src/init_game.c \
		$(PRINTF_PATH) $(GNL_PATH)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean
