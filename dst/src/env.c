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

char			*env_findvalue(t_vector *env, char *name)
{
	int				i;
	t_env_item		*item;

	i = 0;
	item = env_item_find(env, name);
	if (item)
		return (item->value);
	return (NULL);
}

void			env_set(t_vector *env, char *name, char *value)
{
	t_env_item		*item;
	char			*full;

	//checkerror here (double = for example);
	full = ft_strnew(ft_strlen(value) + ft_strlen(name) + 1);
	full = ft_strcat(full, name);
	full = ft_strcat(full, "=");
	full = ft_strcat(full, value);
	item = env_item_find(env, name);
	if (item)
	{
		item->value = value;
		item->full = full;
	}
	else
	{
		vector_add(env, env_item_new(full));
	}
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

t_vector		*env_arm_init(t_vector *env, int ac, char **av)
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
