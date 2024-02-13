NAME = push_swap

LIBFT_PATH = ./libft_1.1

LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = ./src
SRCS = $(SRC_DIR)/push_swap.c \
	   $(SRC_DIR)/push_swap_utils_arg.c \
	   $(SRC_DIR)/push_swap_utils_init.c \
	   $(SRC_DIR)/push_swap_utils_rev.c \
	   $(SRC_DIR)/push_swap_utils_rot.c \
	   $(SRC_DIR)/push_swap_utils_s_p.c \
	   $(SRC_DIR)/push_swap_utils_sort.c \
	   $(SRC_DIR)/push_swap_utils_sort_big.c \
	   $(SRC_DIR)/push_swap_utils_sort_cheapest.c \
	   $(SRC_DIR)/push_swap_utils_sort_moves.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

INCLUDE = -L $(LIBFT_PATH) -lft

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

$(OBJS): $(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
