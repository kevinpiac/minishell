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
	this->builtins_func[0] = &builtin_cd;
	//this->execute = &bm_execute;
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

void				bm_execute(t_bm *this, int i, char **args)
{
	void			(*func_ptr)(char **args);
	ft_putendl("executing : ");
	func_ptr = this->builtins_func[i];
	func_ptr(args);
}
