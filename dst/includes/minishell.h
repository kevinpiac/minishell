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
	t_vector			*env;
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
int						bm_execute(t_bm *this, int func_index, t_dm *dm);

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
**	ENV_ITEM.C
*/

typedef	struct 			s_env_item
{
	char				*name;
	char				*value;
	char				*full;
}						t_env_item;

t_env_item				*env_item_new(char *env_line);
t_env_item				*env_item_find(t_vector *env, char *name);
void					env_item_init(t_env_item *this, char *env_line);

/*
**	ENV.C
*/

char					*env_findvalue(t_vector *env, char *name);
t_vector				*env_arm_init(t_vector *env, int ac, char **av);
t_vector				*env_tovector(char **env);
void					env_set(t_vector *env, char *name, char *value);

/*
**	BUILTIN.C
*/

int						builtin_cd(t_dm *dm);
int						builtin_exit(void);
int						builtin_env(t_dm *dm);
int						builtin_setenv(t_dm *);
int						builtin_unsetenv(t_dm *);

/*
** EXECUTE.C
*/

int						execute(t_dm *dm);
void					execute_binary(t_dm *dm);

#endif
