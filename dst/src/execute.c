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

int				execute(t_dm *dm) // remove env here.
{
	t_bm			*bm;
	int				i;
	char			*bin;

	bin = dm->args[0];
	i = -1;
	bm = bm_new();
	if (bin == NULL)
		return (0);
	if ((i = bm_search(bm, bin)) != -1)
		return (bm_execute(bm, i, dm));
	execute_binary(dm);//replace by dm here
	return (0);
}

static char		*get_first_accessible_path(t_vector *env, char *bin_name)
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

void			execute_binary(t_dm *dm)
{
	pid_t			pid;
	int				status;
	char			*bin;

	bin = get_first_accessible_path(dm->env, dm->args[0]);
	if (!bin)
	{
		ft_putendl_fd("Minishell: command not found or not accessible", 2);
		return ;
	}
	pid = fork();
	if (pid > 1)
		wait(&status);
	else if (pid == 0)
		execve(bin, dm->args, NULL);//should replace null by char **env
	else
		ft_putendl_fd("ERROR", 2);
}
