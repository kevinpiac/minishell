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

/*
** dm_update -> trim line spaces and tabs
*/

void			shell_loop(int ac, char **av, char **env)
{
	int				stop;
	t_dm			*dm;
	char			*line;

	stop = 0;
	(void)ac;
	(void)av;
	dm = dm_new(env);
	while (!stop)
	{
		ft_putstr("$> ");
		get_next_line(1, &line);
		if (!input_error(line, dm->env))
		{
			dm_update(dm, line);
			stop = execute(dm);
		}
	}
}
