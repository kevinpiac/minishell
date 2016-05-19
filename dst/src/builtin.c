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
	char		*pwd;
	t_vector	*env;
	char		*new_pwd;

	args = dm->args;
	env = dm->env;
	pwd = env_findvalue(env, "PWD");
	new_pwd = NULL;
	if (args[1] == NULL && chdir(env_findvalue(env, "HOME")) == 0)
	{
			env_set(env, "OLDPWD", pwd);
			env_set(env, "PWD", getcwd(new_pwd, sizeof(char *)));
	}
	else if (args[1] != NULL && chdir(args[1]) == 0)
	{
		env_set(env, "OLDPWD", pwd);
		env_set(env, "PWD", getcwd(new_pwd, sizeof(char *)));
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
	t_dm		*dmcp;
	char		*bin;

	dmcp = dm_dup(dm);
	i = 1;
	while (i < dm->ac)
	{
		if (ft_strequ(dm->args[i], "-i"))
			env_clear(dmcp->env);
		if ((bin = get_first_accessible_path(dmcp->env, dm->args[i])))
		{
			dm_dup_update_args(dm, i);
			return (-1);
//			execute(dmcp);
		}
		i++;
	}
	env_show(dm->env);
	return (0);
}

int			builtin_setenv(t_dm *dm)
{
	int			ac;
	int			i;
	char		**split;

	ac = ft_splitcount(dm->args);
	i = 1;
	while (i < ac)
	{
		if ((split = ft_strsplit(dm->args[i], '=')) && ft_splitcount(split) == 2)
			env_set(dm->env, split[0], split[1]);
		else if (i + 1 < ac)
		{
			env_set(dm->env, dm->args[i], dm->args[i + 1]);
			i++;
		}
		else
		{
			ft_putendl_fd("Your should check the setenv usage on google ;D", 2);
			return (0);
		}
		i++;
	}
	return (0);
}

int			builtin_unsetenv(t_dm *dm)
{
	int			ac;
	int			i;
	int			item_index;

	ac = ft_splitcount(dm->args);
	i = 1;
	while (i < ac)
	{
		if ((item_index = env_item_index(dm->env, dm->args[i])) != -1)
		{
			vector_delone(dm->env, item_index);
			ft_putendl("Variable has been removed");
		}
		else
			ft_putendl_fd("unsetenv error message", 2);
		i++;
	}
	return (0);
}
