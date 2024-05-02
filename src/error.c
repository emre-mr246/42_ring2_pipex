/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:27:35 by emgul             #+#    #+#             */
/*   Updated: 2024/05/02 21:45:24 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	input_error(void)
{
	printf("%s", "\033[1;31m=== ERROR ======\n");
	printf("%s", "$ ./pipex infile cmd1 cmd2 outfile\n");
	printf("%s", "OR\n");
	printf("%s", "$ ./pipex_bonus infile cmd1 cmd2 ... cmdn outfile\n");
	printf("%s", "$ ./pipex_bonus here_doc LIMITER cmd1 cmd2 file\n");
	exit(EXIT_FAILURE);
}

void	error(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}
