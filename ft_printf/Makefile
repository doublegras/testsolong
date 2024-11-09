NAME = libftprintf.a

RM = rm -rf

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJ_DIR = obj

GCCFLAGS = -g -Wall -Werror -Wextra

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_printptr.c ft_putnbr.c ft_uputnbr.c ft_xbitoa.c \
	  ft_xitoa.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	gcc -I . -o $@ -c $? $(GCCFLAGS)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
