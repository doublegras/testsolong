NAME = so_long

RM = rm -rf

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJ_DIR = obj

SRC_DIR = src

GCCFLAGS = -g -Wall -Werror -Wextra

MLX_DIR = ./mlx_linux

SRC = main.c move_player.c map_check.c so_long_utils.c path.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MLX)
	make -C $(MLX_DIR) all
	gcc $(GCCFLAGS) -I/usr/include -Iincludes -Imlx_linux -o $@ -c $<

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ_DIR) $(OBJ) $(MLX)
	gcc $(GCCFLAGS) $(OBJ) -L/usr/lib -I includes -Lft_printf -lftprintf -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -o $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean : clean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all
