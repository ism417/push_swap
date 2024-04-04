CC := cc

CFLAGS := -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC := act_a.c act_b.c algos.c lst_op.c ft_utils.c ft_utils2.c error_check.c push_swap.c

B_SRCS = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/act_a.c bonus/act_b.c error_check.c lst_op.c ft_utils2.c ft_utils.c

NAME := push_swap

BONUS := checker

HEADER := push_swap.h

B_HEADER := bonus/push_swap_bonus.h

OBJ := $(SRC:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@make all -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(B_OBJS) $(B_HEADER)
	@make all -C libft
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(BONUS)

clean :
	make clean -C libft
	rm -rf $(OBJ) $(B_OBJS)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME) $(BONUS)

re : clean fclean all bonus

.PHONY : all clean fclean re