/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:10 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 10:30:31 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static char	**ft_build_delim(char *str);

int	ft_here_doc_fork(char *limiter, char *file)
{
	pid_t	pid;

	signal(SIGINT, ft_sigint_hd);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
		create_tmp_file(limiter, file);
	waitpid(pid, 0, 0);
	return (1);
}

int	ft_add_heredoc(char *cmd, int *i)
{
	char	*value;
	int		len;
	char	**split;

	split = ft_check_delim(&cmd[*i], &len, i);
	if (!split)
		return (len);
	if (!ft_here_doc_fork(split[1], "/tmp/heredoc_tmp"))
		return (1);
	value = ft_strdup("<< /tmp/heredoc_tmp");
	if (!value)
		return (1);
	ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
	len = 0;
	while (ft_strncmp(&cmd[len], split[1], ft_strlen(split[1])) != 0)
		++len;
	len += ft_strlen(split[1]);
	*i += len;
	ft_free_2d(split);
	g_shell.here_doc = true;
	return (0);
}

void	create_tmp_file(char *limiter, char *file)
{
	char	*line;
	int		tmp_fd;

	signal(SIGINT, ft_sigint_hdc);
	tmp_fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (tmp_fd == -1)
	{
		perror("Failed to create temp file");
		exit (1);
	}
	line = readline(">");
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(tmp_fd, line, ft_strlen(line));
		write(tmp_fd, "\n", 1);
		free(line);
		line = readline(">");
	}
	close(tmp_fd);
	exit(0);
}

char	**ft_check_delim(char *str, int	*err, int *i)
{
	char	**ret;

	if (str[2] == 32)
	{
		ret = ft_split(str, 32);
		if (!ret)
			return (NULL);
	}
	else if (!(ft_isalnum(str[2])))
	{
		ft_printf("minishell: ");
		ft_putstr_fd("syntax error near unexpected token `newline'", 2);
		*err = 2;
		*i += 2;
		ft_int_handler(2);
		return (NULL);
	}
	else
		ret = ft_build_delim(str);
	return (ret);
}

static char	**ft_build_delim(char *str)
{
	char	**ret;
	int		len;

	ret = malloc(3 * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[0] = ft_strdup("<<");
	if (!ret[0])
		return (NULL);
	len = 0;
	while (ft_isalnum(str[len + 2]))
		++len;
	ret[1] = ft_substr(str, 2, len);
	if (!ret[1])
		return (NULL);
	ret[2] = NULL;
	return (ret);
}
