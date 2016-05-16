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

t_dm				*dm_new(char **env, char *line)
{
	t_dm		*dm;

	if (!(dm = (t_dm *)ft_memalloc(sizeof(t_dm) * 1)))
		return (NULL);
	dm_init(dm, env, line);
	return (dm);
}

void				dm_init(t_dm *this, char **env, char *line)
{
	t_vector	*arm;
	int			ac;
	char 		**av;

	av = ft_strsplit(line, ' ');
	ac = ft_splitcount(av);
	arm = env_arm_init(env, ac, av);
	this->arm = arm;
	this->env = env_tovector(env);
	this->args = av;
}
