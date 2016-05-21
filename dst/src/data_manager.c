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
	shell_updatelvl(this->env);
	this->arm = NULL;
	this->args = NULL;
}

void				dm_update(t_dm *this, char *line)
{
	int			ac;
	char		**av;
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
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

void				dm_dup_update_args(t_dm *this, char **args, int index)
{
	char		**new_args;
	int			i;

	i = 0;
	new_args = (char **)ft_memalloc(sizeof(char *) * 1000);
	while (args[index])
	{
		new_args[i] = ft_strdup(args[index]);
		i++;
		index++;
	}
	this->args = new_args;
	this->ac = ft_splitcount(this->args);
}
