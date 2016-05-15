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
	int				status;

	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		//1. get args
		if (get_next_line(1, &line))
		{	//2. split args
			args = ft_strsplit(line, ' ');
			free(line);
			args_c = get_ac(args);
			//3. execute args
			status = execute(args, env);
		}
	}
}
