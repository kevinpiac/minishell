/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*env_findvalue(char **env, char *name)
{
	int			i;
	char		**split;
	char		*value;

	i = 0;
	value = NULL;
	while (env[i])
	{
		split = ft_strsplit(env[i], '=');
		if (ft_strequ(split[0], name))
			value = ft_strdup(split[1]);
		free(split);
		i++;
	}
	return (value);
}
