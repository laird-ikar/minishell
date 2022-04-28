/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:06:36 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/28 08:44:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	init(t_mshell *mshell, char **envp);
static void	tini(void);
static void	set_env(t_mshell *t_mshell, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_mshell	mshell;

	init(&mshell, envp);
	while (mshell.running)
	{
		update_prompt(&mshell);
		mshell.line = readline(mshell.prompt);
		if (!mshell.line)
			continue ;
		add_history(mshell.line);
		ft_lex(&mshell, mshell.token, mshell.line);
		ft_parse(&mshell.command, mshell.token);
		ft_execute(&mshell, &mshell.command);
	}
	tini();
	(void) argc;
	(void) argv;
}

static void	init(t_mshell *mshell, char **envp)
{
	mshell->running = 1;
	mshell->env_size = 0;
	mshell->line = NULL;
	ft_bzero(mshell->env, sizeof (t_env) * MAX_TAB);
	ft_bzero(mshell->token, sizeof (t_token) * MAX_TAB);
	set_env(mshell, envp);
}

static void	tini(void)
{
	rl_clear_history();
}

static void	set_env(t_mshell *mshell, char **envp)
{
	char	*value;
	char	name[MAX_TAB];
	int		name_size;

	while (*envp)
	{
		value = ft_strchr(*envp, '=');
		name_size = value - *envp + 1;
		value++;
		ft_strlcpy(name, *envp, name_size);
		ft_setenv(mshell, name, value, EXPORTED);
		envp++;
	}
	ft_setenv(mshell, "?", "0", LOCAL);
}
