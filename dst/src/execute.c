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

int				execute(t_dm *dm)
{
	t_bm			*bm;
	int				i;
	char			*bin;

	bin = dm->args[0];
	i = -1;
	bm = bm_new();
	if (bin != NULL && !error_tilde(dm->args, dm->env))
	{
		if ((i = bm_search(bm, bin)) != -1)
			return (bm_execute(bm, i, dm));
		execute_binary(dm);
	}
	return (0);
}

char			*get_first_accessible_path(t_vector *env, char *bin_name)
{
	int				i;
	char			*b;
	char			*bin;
	char			**paths;
	char			*val;

	if (((bin_name[0] == '.' && bin_name[1] == '/') || bin_name[0] == '/')
	&& access(bin_name, X_OK) == 0)
		return (bin_name);
	else if ((val = env_findvalue(env, "PATH"))
	&& (paths = ft_strsplit(val, ':')))
	{
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
	}
	error_print(1, bin_name, NULL);
	return (NULL);
}

void			execute_binary(t_dm *dm)
{
	pid_t			pid;
	int				status;
	char			*bin;

	if (is_dir(dm->args[0]))
	{
		error_print(0, dm->args[0], "Permission denied");
		return ;
	}
	bin = get_first_accessible_path(dm->env, dm->args[0]);
	if (!bin)
		return ;
	pid = fork();
	if (pid > 1)
		wait(&status);
	else if (pid == 0)
		execve(bin, dm->args, env_totab(dm->env));
	else
		error_print(0, NULL, "Fork command failed");
}
