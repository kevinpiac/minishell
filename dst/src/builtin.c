/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:33:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_cd(char **args)
{
	ft_putendl("Cd builtin");
	(void)args;
	return (1);
}

int			builtin_exit(void)
{
	ft_putendl("Exit()");
	return (0);
}

int			builtin_env(char **args)
{
	ft_putendl("Env builtin");
	(void)args;
	return (1);
}

int			builtin_setenv(char **args)
{
	ft_putendl("Setenv builtin");
	(void)args;
	return (1);
}

int			builtin_unsetenv(char **args)
{
	ft_putendl("Unsetenv builtin");
	(void)args;
	return (1);
}
