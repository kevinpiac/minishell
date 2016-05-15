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
	this->bultins = ft_strsplit(BUILTINS_LIST, ',');
}
