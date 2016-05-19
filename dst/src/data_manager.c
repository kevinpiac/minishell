/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dm				*dm_new(char **env)
{
	t_dm		*dm;

	if (!(dm = (t_dm *)ft_memalloc(sizeof(t_dm) * 1)))
		return (NULL);
	dm_init(dm, env);
	return (dm);
}

void				dm_init(t_dm *this, char **env_old)
{
	t_vector	*env;

	env = env_tovector(env_old);
	this->env = env;
	this->arm = NULL;
	this->args = NULL;
}

void				dm_update(t_dm *this, char *line)
{
	int			ac;
	char		**av;

	av = ft_strsplit(line, ' ');
	ac = ft_splitcount(av);
//	this->arm = env_arm_init(this->env, ac, av);
	this->args = av;
	this->ac = ac;
}

t_dm				*dm_dup(t_dm *this)
{
	t_dm		*cp;
	char		**env;

	if (!(cp = (t_dm *)ft_memalloc(sizeof(t_dm) * 1)))
		return (NULL);
	env = env_totab(this->env);
	cp->env = env_tovector(env);
	cp->arm = NULL;
	cp->args = NULL;
	return (cp);
}

void				dm_dup_update_args(t_dm *this, int index)
{
	char		**args;

	args = &(this->args[index]);
	int i = 0;
	while (args[i])
	{
		ft_putendl(args[i]);
		i++;
	}
}
