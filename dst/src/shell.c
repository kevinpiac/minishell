/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			shell_loop(int ac, char **av, char **env)
{
	int				stop;
	t_dm			*dm;
	char			*line;
	char			*fullpath;

	stop = 0;
	dm = dm_new(env);
	fullpath = NULL;
	while (!stop)
	{
		if (ac > 1 && ft_strequ(av[1], "--path"))
			ft_putstr(getcwd(fullpath, sizeof(char *)));
		else if (ac > 1)
		{
			error_print(0, "minishell", "usage [--path]");
			return ;
		}
		ft_putstr("$> ");
		get_next_line(1, &line);
		dm_update(dm, line);
		stop = execute(dm);
	}
}

void			shell_updatelvl(t_vector *env)
{
	char			*clvl;
	int				ilvl;

	ilvl = 0;
	if ((clvl = env_findvalue(env, "SHLVL")))
		ilvl = ft_atoi(clvl);
	if (ilvl >= 1)
		ilvl++;
	else
		ilvl = 1;
	env_set(env, "SHLVL", ft_itoa(ilvl));
}
