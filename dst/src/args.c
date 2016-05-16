/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:37:12 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/28 14:37:01 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**args_make(t_vector *arm, char **env)
{
	(void)arm;
	(void)env;
	return (ft_strsplit("ls -la", ' '));
}
