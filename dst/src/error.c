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
	int			j;
	int			count;

	count = 0;
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && args[i][j] == '~')
				count++;
			j++;
		}
		i++;
	}
	if (count > 0 && !env_findvalue(env, "HOME"))
	{
		error_print(0, "~", "Unable to find HOME value in env");
		return (1);
	}
	return (0);
}
