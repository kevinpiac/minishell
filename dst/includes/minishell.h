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
# include <termios.h>
# include <term.h>
# define BUILTINS_LIST "cd,exit,env,setenv,unsetenv"

/*
**	DATA_MANAGER.C
*/

typedef struct			s_dm
{
	t_vector			*arm;
	char				**env;
	char				**args;
}						t_dm;

t_dm					*dm_new(char **env, char *line);
void					dm_init(t_dm *this, char **env, char *line);

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
int						bm_execute(t_bm *this, int func_index, char **args
							, char **env);

/*
**	ARGS.C
*/

char					**args_make(t_vector *arm, char **env);

/*
**	SHELL.C
*/

void					shell_loop(int ac, char **av, char **env);
void					shell_launch(char **av);

/*
**	ENV.C
*/

char					*env_findvalue(char **env, char *name);
t_vector				*env_arm_init(char **env, int ac, char **av);

/*
**	BUILTIN.C
*/

int						builtin_cd(char **args, char **env);
int						builtin_exit(void);
int						builtin_env(char **args, char **env);
int						builtin_setenv(char **args);
int						builtin_unsetenv(char **args);

/*
** EXECUTE.C
*/

int						execute(t_dm *dm, char **env);
void					execute_binary(char **args, char **env);

#endif
