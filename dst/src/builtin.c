/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_cd(char **args, char **env)
{
	if (args[1] == NULL || ft_strequ(args[1], "~"))
	{
		if (chdir(env_findvalue(env, "HOME")) != 0)
			ft_putendl_fd("cd: an error occured", 2);
		else
			env[0] = ft_strdup("COUCOU");
	}
	else if (chdir(args[1]) != 0)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(args[1], 2);
	}
	return (0);
}

int			builtin_exit(void)
{
	ft_putendl("Exiting...");
	return (1);
}

int			builtin_env(t_dm *dm)
{
	int			i;
	t_env_item	*item;

	i = 0;
	while (i < dm->env->total)
	{
		item = dm->env->items[i];
		ft_putendl(item->full);
		i++;
	}
	return (0);
}

int			builtin_setenv(char **args)
{
	ft_putendl("Setenv builtin");
	(void)args;
	return (0);
}

int			builtin_unsetenv(char **args)
{
	ft_putendl("Unsetenv builtin");
	(void)args;
	return (0);
}
