NAME = push_swap

NAME1 = checker

NAME2 = ps_bonus

SRCS = atob.c btoa.c ft_split.c push_swap.c instructions.c  instructio.c instructions2.c firstsort.c linkedlist.c args.c

SRCS1 = push_swap_bonus/atob_bonus.c push_swap_bonus/btoa_bonus.c push_swap_bonus/instructio_bonus.c push_swap_bonus/ft_split_bonus.c push_swap_bonus/push_swap_bonus.c push_swap_bonus/instructions_bonus.c push_swap_bonus/instructions2_bonus.c push_swap_bonus/firstsort_bonus.c push_swap_bonus/linkedlist_bonus.c push_swap_bonus/args_bonus.c

SRCS_B = push_swap_bonus/checker_bonus.c push_swap_bonus/instructio_bonus.c push_swap_bonus/get_next_line_bonus.c push_swap_bonus/get_next_line_utils_bonus.c push_swap_bonus/ft_strcmp_bonus.c push_swap_bonus/ft_split_bonus.c push_swap_bonus/instruchecker_bonus.c push_swap_bonus/checker_utils_bonus.c push_swap_bonus/instru2checker_bonus.c push_swap_bonus/linkedlist_bonus.c 

CFLAGS = -Wall -Werror -Wextra

OBJS1 = ${SRCS1:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_B)
	cc $(CFLAGS) $(OBJS_B) -o $(NAME1)

$(NAME2): $(OBJS1)
	cc $(CFLAGS) $(OBJS1) -o $(NAME2)

clean:
	rm -rf $(OBJS) $(OBJS_B) $(OBJS1)

fclean: clean
	rm -rf $(NAME) $(NAME2) $(NAME1)

re: fclean all
