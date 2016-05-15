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

int				execute(char **args, char **env)
{
	t_bm			*bm;
	int				i;

	bm = bm_new();
	if (args[0] == NULL)
		return (0);
	if ((i = bm->search(bm, args[0])) != -1)
		return (bm->execute(bm, i, args));
	execute_binary(args, env);
	return (0);
}

void			execute_binary(char **args, char **env)
{
	pid_t			pid;
	int				status;
	char			*bin;

	bin = ft_strjoin("/bin/", args[0]);
	pid = fork();
	if (pid > 1)
		wait(&status);
	else if (pid == 0)
		execve(bin, args, env);
	else
		ft_putendl_fd("ERROR", 2);
}
