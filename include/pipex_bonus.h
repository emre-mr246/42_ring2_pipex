/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:33:38 by emgul             #+#    #+#             */
/*   Updated: 2024/04/10 23:34:03 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

void	input_error(void);
void	error(char *error_message);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

#endif