/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:06:36 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/14 07:35:01 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	init(t_mshell *mshell, char **envp);
static void	tini(/*t_mshell *mshell*/);
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
		ft_lex(mshell.tokens, mshell.line);
		ft_parse(&mshell.command, mshell.tokens);
		ft_execute(&mshell.command);
	}
	tini(&mshell);
	(void) argc;
	(void) argv;
}

static void	init(t_mshell *mshell, char **envp)
{
	mshell->running = 1;
	mshell->env_size = 0;
	mshell->line = NULL;
	ft_bzero(mshell->env, sizeof (t_env) * MAX_TAB);
	set_env(mshell, envp);
}

static void	tini(/*t_mshell *mshell*/)
{
	rl_clear_history();
}

static void	set_env(t_mshell *mshell, char **envp)
{
	char	*value;
	char	name[MAX_TAB] = "test du cul";
	int		name_size;

	while (*envp)
	{
		// ft_printf("%s", *envp);
		value = ft_strchr(*envp, '=');
		name_size = value - *envp + 1;
		value++;
		ft_strlcpy(name, *envp, name_size);
		ft_setenv(mshell, name, value, EXPORTED);
		envp++;
	}
}
