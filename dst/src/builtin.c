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
	pwd = NULL;
	pwd = getcwd(pwd, sizeof(char *));
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
		error_print(2, args[1], NULL);
	return (0);
}

int			builtin_exit(t_dm *dm)
{
	char		*clvl;
	int			ilvl;

	ft_putendl("Exiting...");
	if ((clvl = env_findvalue(dm->env, "SHLVL")))
	{
		ilvl = ft_atoi(clvl);
		if (ilvl == 3)
			ft_putendl("Never give up!");
		else if (ilvl == 2)
			ft_putendl("Hope to see you soon :'(");
		else
		{
			ft_putnbr(ilvl - 2);
			ft_putendl(" level(s) remaining.");
		}
	}
	return (1);
}

int			builtin_env(t_dm *dm)
{
	int			i;
	t_dm		*dmcp;
	int			once;

	dmcp = dm_dup(dm);
	i = 1;
	once = 0;
	while (i < dm->ac)
	{
		if (ft_strequ(dm->args[i], "-i") && !once++)
			option_env_clear(dmcp->env);
		else if (ft_strequ(dm->args[i], "-u") && dm->args[i + 1])
			option_env_unset(dmcp->env, dm->args[++i]);
		else if (ft_strchr(dm->args[i], '='))
			option_env_set(dmcp->env, dm->args[i]);
		else
		{
			dm_dup_update_args(dmcp, dm->args, i);
			return (execute(dmcp));
		}
		i++;
	}
	env_show(dmcp->env);
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
		if ((split = ft_strsplit(dm->args[i], '='))
			&& ft_splitcount(split) == 2)
			env_set(dm->env, split[0], split[1]);
		else if (i + 1 < ac)
		{
			env_set(dm->env, dm->args[i], dm->args[i + 1]);
			i++;
		}
		else
		{
			error_print(0, "setenv", "usage: [name=value] or [name value]");
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
			error_print(0, dm->args[i], "variable does not exist");
		i++;
	}
	return (0);
}
