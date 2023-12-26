NAME	:=	pushswap

# Compiler
CC	:=	cc
CFLAGS	:=	-Wextra -Wall -Werror

# Libft
LIBFT_PATH	:=	./lib/libft/
LIBFT_NAME	:=	libft.a
LIBFT		:=	$(LIBFT_PATH)$(LIBFT_NAME)

# ft_printf
FT_PRINTF_PATH	:=	./lib/ft_printf/
FT_PRINTF_NAME	:=	libftprintf.a
FT_PRINTF		:=	$(FT_PRINTF_PATH)$(FT_PRINTF_NAME)

# Includes
INC	:=	-I ./lib/libft \
		-I ./lib/ft_printf

# Source
SRCS	:=	src/pushswap.c \
			src/operations/basic_operations.c \
			src/operations/swap.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c

OBJS	:=	$(SRCS:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

# Making Libft
$(LIBFT):
	@echo "Making Libft..."
	@make -sC $(LIBFT_PATH)

# Making ft_printf
$(FT_PRINTF):
	@echo "Making ft_printf..."
	@make -sC $(FT_PRINTF_PATH)

%.o: %c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

# Compiling PushSwap
$(NAME): $(OBJS)
	@echo "Compiling PushSwap..."
	@$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(INC) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(FT_PRINTF_PATH)

fclean: clean
	@echo "Cleaning PushSwap..."
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(FT_PRINTF)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx