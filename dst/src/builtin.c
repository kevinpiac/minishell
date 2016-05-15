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

int			builtin_cd(char **args)
{
	if (args[1] != NULL)
	{
		if (chdir(args[1]) != 0)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putendl_fd(args[1], 2);
		}
	}
	return (0);
}

int			builtin_exit(void)
{
	ft_putendl("Exiting...");
	return (1);
}

int			builtin_env(char **args, char **env)
{
	int			i;

	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
	(void)args;
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
