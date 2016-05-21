/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:33:27 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:37:03 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					error_tilde(char **args, t_vector *env)
{
	int			i;
	char		*home;

	i = 0;
	home = env_findvalue(env, "HOME");
	while (args[i])
	{
		if (args[i][0] == '~')
		{
			if (home && args[i][1])
				args[i] = ft_strjoin(home, &args[i][1]);
			else if (home)
				args[i] = ft_strdup(home);
			else
			{
				error_print(0, "~", "Unable to find HOME value in env");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
