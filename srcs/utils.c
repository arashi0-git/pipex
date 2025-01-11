/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:54:03 by aryamamo          #+#    #+#             */
/*   Updated: 2025/01/10 13:52:22 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	handle_child1(char **av, char **env, int *pipefd)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
		error("fork failed");
	if (pid1 == 0)
	{
		close(pipefd[0]);
		child_process(av, env, pipefd);
	}
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
}

void	handle_child2(char **av, char **env, int *pipefd)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		error("fork failed");
	if (pid2 == 0)
	{
		close(pipefd[1]);
		parent_process(av, env, pipefd);
	}
	close(pipefd[0]);
	waitpid(pid2, NULL, 0);
}

void	error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
