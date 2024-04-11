/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:11:26 by emgul             #+#    #+#             */
/*   Updated: 2024/04/11 00:12:11 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <sys/types.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

void	child_process(char **argv, char **envp, int *fd)
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY, 0444);
	if (input_file == -1)
		error("Unable to open input_file");
	dup2(input_file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		error("Unable to open outFile");
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		input_error();
	if (pipe(fd) == -1)
		error("Pipe creation failed");
	pid = fork();
	if (pid == -1)
		error("Fork failed");
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(-1, NULL, 0);
	if (pid != 0)
		parent_process(argv, envp, fd);
	return (0);
}
