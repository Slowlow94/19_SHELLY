NAME	= minishell
SRCS	= libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memccpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strcmp.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_strjoin.c \
		libft/ft_substr.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstdelone_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstiter_bonus.c \
		libft/ft_lstmap_bonus.c \
		libft/ft_printf.c \
		libft/ft_printf_2.c \
		libft/get_next_line.c \
		libft/get_next_line_utils.c \
		SRCS/s_main.c \
		SRCS/builtins_utils.c \
		SRCS/builtins_echo.c \
		SRCS/builtins_echo_2.c \
		SRCS/builtins_cd.c \
		SRCS/builtins_pwd.c \
		SRCS/builtins_export.c \
		SRCS/builtins_export_2.c \
		SRCS/builtins_export_without_arg.c \
		SRCS/builtins_unset.c \
		SRCS/builtins_env.c \
		SRCS/builtins_exit.c \
		SRCS/initialisation_structure.c \
		SRCS/free.c

OBJS	= ${SRCS:.c=.o}
INCS	= -IINCS
CC		= gcc -fsanitize=address -g
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re