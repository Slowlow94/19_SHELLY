NAME = minishell

USR = ${USER}

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
		SRCS/builtins/free_builtins.c \
		SRCS/initialisation_structure.c \
		SRCS/parsing/analyzer.c \
		SRCS/parsing/add_node.c \
		SRCS/parsing/parse_utils.c \
		SRCS/parsing/parser.c \
		SRCS/parsing/tokenizer.c \
		SRCS/parsing/var_env_utils.c \
		SRCS/parsing/value_utils.c \
		SRCS/parsing/here_doc.c \
		SRCS/parsing/split_utils.c \
		SRCS/parsing/expand_utils.c \
		SRCS/parsing/ft_expand.c \
		SRCS/parsing/ft_split_quote.c \
		SRCS/parsing/error.c \
		SRCS/signal/signal.c \
		SRCS/execution/process.c \
		SRCS/execution/child_process.c \
		SRCS/execution/parent_process.c \
		SRCS/execution/handle_cmds_redirections.c \
		SRCS/execution/linked_list.c \
		SRCS/execution/linked_list_2.c \
		SRCS/execution/parsing_path_pipe.c \
		SRCS/execution/parsing_relative_absolut.c \
		SRCS/execution/no_pipe.c \
		SRCS/execution/free.c \
		SRCS/execution/free_exec.c \
		SRCS/execution/ft_argv_cmd.c \
		SRCS/main.c \
		SRCS/utils.c

CC = cc

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

OBJS = $(SRCS:.c=.o)

INCS = -L $(LIBFT_PATH) -lft -lreadline -lhistory
$(NAME) : $(OBJS)
	make bonus -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCS) -L /Users/$(USR)/.brew/opt/readline/lib

$(OBJS): $(SRC_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I /Users/$(USR)/.brew/opt/readline/include


all: $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
