/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				execute_builtin(char **args)
{
	int				i;
	t_bm			*bm;

	i = 0;
	(void)args;
	bm = bm_new();

	return (1);
}

void			execute_binary(char **args, char **env)
{
	pid_t			pid;
	int				status;

	pid = fork();
	if (pid > 1)
		wait(&status);
	else if (pid == 0)
		execve(args[0], args, env);
	else
		ft_putendl_fd("ERROR", 2);
}
