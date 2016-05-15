/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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

void			shell_launch(char **av)
{
	pid_t			pid;
	int				status;

	pid = fork();
	if (pid > 1)
	{
		ft_putendl("Im the father");
		wait(&status);
	}
	else if (pid == 0)
	{
		ft_putendl("Im the son");
		execve("/bin/ls", av, NULL);
	}
	else
		ft_putendl("ERROR");
}

void			shell_loop(void)
{
	char			*line;
	char			**av;
	int				ac;

	while (1)
	{
		ft_putstr("$> ");
		//1. get args
		if (get_next_line(1, &line))
		{	//2. split args
			av = ft_strsplit(line, ' ');
			ac = get_ac(av);
			//3. execute args
			shell_launch(av);
		}
	}
}
