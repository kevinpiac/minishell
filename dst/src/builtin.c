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

int			builtin_cd(t_dm *dm)
{
	char		**args;
	char		*home;
	char		*pwd;
	t_vector	*env;

	args = dm->args;
	env = dm->env;
	home = env_findvalue(env, "HOME");
	pwd = env_findvalue(env, "PWD");
	if (args[1] == NULL && chdir(home) == 0)
	{
			env_set(env, "OLDPWD", pwd);
			env_set(env, "PWD", home);
	}
	else if (args[1] != NULL && chdir(args[1]) == 0)
	{
		env_set(env, "OLDPWD", pwd);
		env_set(env, "PWD", args[1]); // modify here
	}
	else
		ft_putendl_fd("cd: An error occured, no such file of directory.", 2);
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

int			builtin_setenv(t_dm *dm)
{
	(void)dm;
	ft_putendl("Setenv builtin");
	return (0);
}

int			builtin_unsetenv(t_dm *dm)
{
	ft_putendl("Unsetenv builtin");
	(void)dm;
	return (0);
}
