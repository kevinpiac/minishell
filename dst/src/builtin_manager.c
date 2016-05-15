/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bm				*bm_new(void)
{
	t_bm		*bm;

	if (!(bm = ft_memalloc(sizeof(bm) * 1)))
		return (NULL);
	bm_init(bm);
	return (bm);
}

void				bm_init(t_bm *this)
{
	this->builtins = ft_strsplit(BUILTINS_LIST, ',');
}

void				bm_del(t_bm *this)
{
	if (this)
		free(this);
	this = NULL;
}

int					bm_search(t_bm *this, char *name)
{
	int			i;

	i = 0;
	while (this->builtins[i])
	{
		if (ft_strequ(this->builtins[i], name))
			return (i);
		i++;
	}
	return (-1);
}

int					bm_execute(t_bm *this, int i, char **args, char **env)
{
	int			(*builtins_ptr[5])();

	builtins_ptr[0] = &builtin_cd;
	builtins_ptr[1] = &builtin_exit;
	builtins_ptr[2] = &builtin_env;
	builtins_ptr[3] = &builtin_setenv;
	builtins_ptr[4] = &builtin_unsetenv;
	free(this);
	return (builtins_ptr[i](args, env));
}
