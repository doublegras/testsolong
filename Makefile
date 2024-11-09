NAME = so_long

RM = rm -rf

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJ_DIR = obj

SRC_DIR = src

GCCFLAGS = -g -Wall -Werror -Wextra

SRC = main.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(GCCFLAGS) -I/usr/include -Iincludes -Imlx_linux -o $@ -c $? 

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ_DIR) $(OBJ)
	gcc $(GCCFLAGS) $(OBJ) -L/usr/lib -I includes -Lft_printf -lftprintf -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -o $(NAME)


$(PRINTF):
	make -C $(PRINTF_DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJ_DIR)

fclean : clean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all
