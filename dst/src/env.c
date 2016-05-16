/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*env_findvalue(char **env, char *name)
{
	int				i;
	char			**split;
	char			*value;

	i = 0;
	value = NULL;
	while (env[i])
	{
		split = ft_strsplit(env[i], '=');
		if (ft_strequ(split[0], name))
			value = ft_strdup(split[1]);
		free(split);
		i++;
	}
	return (value);
}

t_vector		*env_tovector(char **env)
{
	t_vector		*v_env;
	int				i;

	i = 0;
	v_env = vector_new(30);
	while (env[i])
	{
		vector_add(v_env, env_item_new(env[i]));
		i++;
	}
	return (v_env);
}

t_vector		*env_arm_init(char **env, int ac, char **av)
{
	t_vector		*arm;
	t_arm_argument	*param;
	char			*new_val;
	char			*new_arg;
	int				i;

	i = 0;
	arm = arm_init(ac, av);
	while (i < arm->total)
	{
		param = arm->items[i];
		new_val = ft_strreplace(param->name, "~", env_findvalue(env, "HOME"));
		if (new_val)
		{
			param->name = new_val;
			break;
		}
		i++;
	}
	i = 0;
	while (av[i])
	{
		new_arg = ft_strreplace(av[i], "~", env_findvalue(env, "HOME"));
		if (new_arg)
		{
			av[i] = new_arg;
			break;
		}
		i++;
	}
	return (arm);
}
