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

void			shell_execute(char **args, char **env)
{
	(void)env;
	if (execute_builtin(args) == -1)
		execute_binary(args, env);
}

void			shell_loop(char **env)
{
	char			*line;
	char			**args;
	int				args_c;

	while (1)
	{
		ft_putstr("$> ");
		//1. get args
		if (get_next_line(1, &line))
		{	//2. split args
			args = ft_strsplit(line, ' ');
			args_c = get_ac(args);
			//3. execute args
			shell_execute(args, env);
		}
	}
}
