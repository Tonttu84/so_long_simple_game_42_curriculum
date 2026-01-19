
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#Name of the executable
NAME = so_long


SRCS = check.c ft_atoi_spec.c ft_calloc.c ft_printf.c monsters.c\
       ft_put_hex.c ft_put_int.c ft_put_txt.c ft_split.c ft_strdup.c \
       get_next_line.c get_next_line_utils.c init.c move.c render.c \
       so_long.c terminate.c utils.c minis.c

OBJS = $(SRCS:.c=.o)


MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a


LIBS = -L$(MLX_DIR) -lmlx_Linux -L/lib/x86_64-linux-gnu -lXext -lX11


all: $(NAME)

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)


$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	@if [ -d $(MLX_DIR) ]; then \
	$(MAKE) -C $(MLX_DIR) clean; \
	fi


fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)

re: fclean all


