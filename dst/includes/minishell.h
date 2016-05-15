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
	char				**builtins;
}						t_bm;

t_bm					*bm_new(void);
void					bm_init(t_bm *this);
void					bm_del(t_bm *this);
int						bm_search(t_bm *this, char *name);
int						bm_execute(t_bm *this, int func_index, char **args);

/*
**	SHELL.C
*/

void					shell_loop(char **env);
void					shell_launch(char **av);

/*
**	BUILTIN.C
*/

int						builtin_cd(char **args);
int						builtin_exit(void);
int						builtin_env(char **args);
int						builtin_setenv(char **args);
int						builtin_unsetenv(char **args);

/*
**	BUILTIN_MANAGER.C
*/

int						bm_search(t_bm *this, char *name);
int						bm_execute(t_bm *this, int i, char **args);

/*
** EXECUTE.C
*/

int						execute(char **args, char **env);
void					execute_binary(char **args, char **env);

#endif
