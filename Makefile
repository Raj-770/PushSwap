NAME	:=	push_swap

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
		-I ./lib/ft_printf \

# Source
SRCS	:=	src/pushswap.c \
			src/operations/basic_operations.c \
			src/operations/swap.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/parse_args.c \
			src/utils.c \
			src/sorting_algorithms/tiny_sort.c \
			src/sorting_algorithms/mini_sort.c \
			src/sorting_algorithms/middle_sort.c \
			src/sorting_algorithms/middle_sort_utils_1.c \
			src/sorting_algorithms/middle_sort_utils_2.c \
			src/sorting_algorithms/middle_sort_utils_3.c \
			src/sorting_algorithms/middle_sort_utils_4.c

OBJS	:=	$(SRCS:.c=.o)

# Bonus Source
BNS_SRCS	:=	bonus/get_next_line/get_next_line.c \
				bonus/get_next_line/get_next_line_utils.c \
				bonus/checker.c \
				bonus/checker_operations.c \
				src/operations/basic_operations.c \
				src/operations/swap.c \
				src/operations/push.c \
				src/operations/rotate.c \
				src/operations/reverse_rotate.c \
				src/parse_args.c \
				src/utils.c

BNS_OBJS	:=	$(BNS_SRCS:.c=.o)

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

bonus: $(LIBFT) $(FT_PRINTF) checker

checker: $(BNS_OBJS)
	@echo "Compiling Checker..."
	@$(CC) $(CFLAGS) $(BNS_OBJS) $(LIBFT) $(FT_PRINTF) -o $@

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)
	@rm -rf $(BNS_OBJS)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(FT_PRINTF_PATH)

fclean: clean
	@echo "Cleaning PushSwap..."
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(FT_PRINTF)
	@rm -rf checker

re: fclean all

.PHONY: all, clean, fclean, re, libmlx