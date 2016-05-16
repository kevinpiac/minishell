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
	t_vector		*history;
	char			*line;

	history = vector_new(100);
	stop = 0;
	(void)ac;
	(void)av;
	while (!stop)
	{
		ft_putstr("$> ");
		get_next_line(1, &line);
		vector_add(history, ft_strdup(line));
		dm = dm_new(env, line);
		free(line);
		stop = execute(dm);
	}
	vector_del(history, free);
}
