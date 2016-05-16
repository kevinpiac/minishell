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

//remove and add to libft.
static int		get_ac(char **av)
{
	int				i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void			shell_loop(char **env)
{
	char			*line;
	char			**args;
	int				args_c;
	int				stop;
	t_vector		*history;

	history = vector_new(100);
	stop = 0;
	while (!stop)
	{
		ft_putstr("$> ");
		get_next_line(1, &line);
		args = ft_strsplit(line, ' ');
		vector_add(history, ft_strdup(line));
		free(line);
		args_c = get_ac(args);
		stop = execute(args, env);
		free(args);
	}
	vector_del(history, free);
}
