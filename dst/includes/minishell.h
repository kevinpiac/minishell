/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:33:27 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/13 16:37:03 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include "../libft/includes/libft.h"
# define BUILTINS_LIST "cd,exit,env,setenv,unsetenv"

/*
**	BUILTIN_MANAGER.C
*/

typedef struct 			s_bm
{
	char				**bultins;
	void				(*builtin_cd)(char **args);
	void				(*builtin_exit)(char **args);
}						t_bm;

t_bm					*bm_new(void);
void					bm_init(t_bm *this);

/*
**	SHELL.C
*/

void					shell_loop(char **env);
void					shell_launch(char **av);

/*
**	BUILTIN.C
*/

int						builtin_cd(char **args);
int						builtin_exit(char **args);
int						builtin_env(char **args);
int						builtin_setenv(char **args);
int						builtin_unsetenv(char **args);

/*
**	BUILTIN.C
*/

void					execute_binary(char **args, char **env);
int						execute_builtin(char **args);

#endif
