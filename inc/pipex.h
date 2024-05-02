/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:33:36 by emgul             #+#    #+#             */
/*   Updated: 2024/05/02 20:44:25 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// UTILS
void	execute(char *argv, char **envp);
char	*find_valid_path(char *cmd, char **envp);
char	*make_path(char *uncompleted_path, char *cmd);
void	free_array(char **array);

// ERROR
void	input_error(void);
void	error(char *error_message);

// BONUS
void	read_here_doc(char **argv);

#endif