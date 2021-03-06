/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:05:23 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/12/07 15:05:25 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	pipe_free(int **pipe_fd, int nbr_cmd)
{
	int	i;

	i = nbr_cmd - 2;
	while (i >= 0)
	{
		free(pipe_fd[i]);
		pipe_fd[i] = NULL;
		i--;
	}
	free(pipe_fd);
	pipe_fd = NULL;
	return (1);
}

void	main_free(t_data *m, t_cmd *cmd)
{
	int	i;

	if (cmd->nbr_cmd == 1)
	{
		free(m->redir);
		m->redir = NULL;
		free (m);
		m = NULL;
	}
	else
	{
		i = cmd->nbr_cmd - 1;
		while (i >= 0)
		{
			if (m[i].redir->pipe_fd != NULL)
				pipe_free (m[i].redir->pipe_fd, cmd->nbr_cmd);
			free (m[i].redir);
			i--;
		}
		free(m);
	}
}

void	ft_freeptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
