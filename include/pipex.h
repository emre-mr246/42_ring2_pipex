/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:33:36 by emgul             #+#    #+#             */
/*   Updated: 2024/04/10 23:34:01 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

void	input_error(void);
void	error(char *error_message);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

#endif