/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:33:27 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:37:03 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			option_env_clear(t_vector *env)
{
	vector_foreach(env, &env_item_del);
	env->total = 0;
}

void			option_env_unset(t_vector *env, char *name)
{
	int			index;

	if ((index = env_item_index(env, name)) != -1)
	{
		vector_delone(env, index);
		ft_putendl("Variable has been removed");
	}
	else
		error_print(0, name, "Variable does not exist");
}

void			option_env_set(t_vector *env, char *tosplit)
{
	char		**split;
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (tosplit[i])
	{
		if (tosplit[i] == '=')
			count++;
		i++;
	}
	if (count > 1)
	{
		error_print(0, "env", "Variable or name can not contain =");
		return ;
	}
	split = ft_strsplit(tosplit, '=');
	if (split && ft_splitcount(split) == 2)
		env_set(env, split[0], split[1]);
	else
		error_print(0, "env", "usage: [name=value]");
}
