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

	i = -1;
	bm = bm_new();
	if (args[0] == NULL)
		return (0);
	if ((i = bm_search(bm, args[0])) != -1)
		return (bm_execute(bm, i, args, env));
	execute_binary(args, env);
	return (0);
}

static char		*get_first_accessible_path(char **env, char *bin_name)
{
	int				i;
	char			*b;
	char			*bin;
	char			**paths;

	if (access(bin_name, X_OK) == 0)
		return (bin_name);
	paths = ft_strsplit(env_findvalue(env, "PATH"), ':');
	i = 0;
	while (paths[i])
	{
		b = ft_strjoin(paths[i], "/");
		bin = ft_strjoin(b, bin_name);
		free(b);
		if (access(bin, X_OK) == 0)
			return (bin);
		i++;
	}
	return (NULL);
}

void			execute_binary(char **args, char **env)
{
	pid_t			pid;
	int				status;
	char			*bin;
	bin = get_first_accessible_path(env, args[0]);
	if (!bin)
	{
		ft_putendl_fd("Minishell: command not found or not accessible", 2);
		return ;
	}
	pid = fork();
	if (pid > 1)
		wait(&status);
	else if (pid == 0)
		execve(bin, args, env);
	else
		ft_putendl_fd("ERROR", 2);
}
