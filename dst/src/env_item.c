/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_item			*env_item_new(char *env_line)
{
	t_env_item		*env_item;

	if (!(env_item = (t_env_item *)ft_memalloc(sizeof(t_env_item))))
		return (NULL);
	env_item_init(env_item, env_line);
	return (env_item);
}

void				env_item_init(t_env_item *this, char *env_line)
{
	char			**split;
	int				len;
	int				index;

	len = ft_strlen(env_line);
	index = ft_strindex(env_line, "=");
	split = ft_strsplit(env_line, '=');
	this->full = ft_strdup(env_line);
	this->name = ft_strsub(env_line, 0, index - 1);
	this->value = ft_strsub(env_line, index + 1, len - 1);
}
