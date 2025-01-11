/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:40:35 by aryamamo          #+#    #+#             */
/*   Updated: 2025/01/10 13:46:06 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	error(const char *msg);
void	handle_child1(char **av, char **env, int *pipefd);
void	handle_child2(char **av, char **env, int *pipefd);
void	child_process(char **av, char **env, int *fd);
void	parent_process(char **av, char **env, int *fd);

#endif
