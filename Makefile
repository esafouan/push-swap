NAME = push_swap

NAME1 = checker

SRCS = atob.c btoa.c ft_split.c push_swap.c instructions.c  instructio.c instructions2.c firstsort.c linkedlist.c args.c

SRCS_B = push_swap_bonus/checker_bonus.c \
		push_swap_bonus/checker_utils_bonus.c \
		push_swap_bonus/get_next_line_bonus.c \
		push_swap_bonus/get_next_line_utils_bonus.c \
		push_swap_bonus/ft_strcmp_bonus.c \
		push_swap_bonus/instru2checker_bonus.c \
		push_swap_bonus/instruchecker_bonus.c \
 		push_swap_bonus/args_bonus.c \
		push_swap_bonus/ft_split_bonus.c \
		push_swap_bonus/instructio_bonus.c \
		push_swap_bonus/linkedlist_bonus.c \

CFLAGS = -Wall -Werror -Wextra

OBJS_B = ${SRCS_B:.c=.o}

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME1) 

$(NAME1): $(OBJS_B)
	cc $(CFLAGS) -fsanitize=address $(OBJS_B) -o $(NAME1)


clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME) $(NAME1)

re: fclean all
