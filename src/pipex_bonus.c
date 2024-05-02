/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:11:24 by emgul             #+#    #+#             */
/*   Updated: 2024/05/03 00:57:00 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../inc/pipex.h"
#include <unistd.h>
#include <fcntl.h>

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("Pipe creation failed");
	pid = fork();
	if (pid == -1)
		error("Fork failed");
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else if (pid != 0)
	{
		waitpid(-1, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	read_here_doc(char **argv)
{
	int		file;
	char	*line;
	char	*temp_file;

	temp_file = ".here_doc_temp";
	file = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, file);
		free(line);
	}
	close(file);
	file = open(temp_file, O_RDONLY);
	dup2(file, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	argv_index;
	int	in_file;
	int	out_file;

	if (argc < 5)
		input_error();
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		argv_index = 3;
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		read_here_doc(argv);
	}
	else
	{
		argv_index = 2;
		in_file = open(argv[1], O_RDWR);
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(in_file, STDIN_FILENO);
	}
	while (argv_index < argc - 2)
		child_process(argv[argv_index++], envp);
	dup2(out_file, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (0);
}
