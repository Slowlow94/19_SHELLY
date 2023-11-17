NAME = minishell

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

SRCS	= SRCS/builtins/exec_builtins.c \
		SRCS/builtins/builtins_echo.c \
		SRCS/builtins/builtins_cd.c \
		SRCS/builtins/builtins_pwd.c \
		SRCS/builtins/builtins_export.c \
		SRCS/builtins/builtins_export_2.c \
		SRCS/builtins/builtins_export_utils.c \
		SRCS/builtins/builtins_export_check_double.c \
		SRCS/builtins/builtins_export_del.c \
		SRCS/builtins/builtins_export_without_arg.c \
		SRCS/builtins/builtins_export_without_arg_2.c \
		SRCS/builtins/builtins_unset.c \
		SRCS/builtins/builtins_env.c \
		SRCS/builtins/builtins_exit.c \
		SRCS/builtins/actions_in_env.c \
		SRCS/builtins/free.c \
		SRCS/initialisation_structure.c \
		SRCS/parsing/add_node.c \
		SRCS/parsing/parse_utils.c \
		SRCS/parsing/parser.c \
		SRCS/parsing/tokenizer.c \
		SRCS/main.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCS = -L $(LIBFT_PATH) -lft

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCS) -lreadline

$(OBJS): $(SRC_DIR)%.o : $(SRC_DIR)%.c
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