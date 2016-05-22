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

void			env_show(t_vector *env)
{
	int			i;
	t_env_item	*item;

	i = 0;
	while (i < env->total)
	{
		item = env->items[i];
		ft_putendl(item->full);
		i++;
	}
}

void			env_set(t_vector *env, char *name, char *value)
{
	t_env_item		*item;
	char			*full;

	if (ft_strchr(name, '=') || ft_strchr(value, '='))
	{
		error_print(0, NULL, "variable or value can not contain =");
		return ;
	}
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
		vector_add(env, env_item_new(full));
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

char			**env_totab(t_vector *this)
{
	t_env_item		*item;
	int				i;
	char			**array;

	array = (char **)ft_memalloc(sizeof(char *) * this->total + 1);
	i = 0;
	while (i < this->total)
	{
		item = this->items[i];
		array[i] = ft_strdup(item->full);
		i++;
	}
	array[i] = NULL;
	return (array);
}

void			env_clear(t_vector *env)
{
	vector_foreach(env, &env_item_del);
	env->total = 0;
}
