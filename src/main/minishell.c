/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:06:36 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/08 13:22:16 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	init(t_mshell *mshell);
static void	tini(t_mshell *mshell);

int	main(void)
{
	t_mshell	*mshell;

	mshell = malloc(sizeof (t_mshell));
	if (!mshell)
		exit(printf("Error (☞ ಠ_ಠ)☞ %s", strerror));
	init(mshell);
	while (mshell->running)
	{
		update_prompt(mshell);
		mshell->line = readline(mshell->prompt);
		if (!mshell->line)
			continue ;
		add_history(mshell->line);
		mshell->tokens = ft_lex(mshell->line);
		if (!mshell->tokens)
			continue ;
		mshell->command = ft_parse(mshell->tokens);
		if (!mshell->command)
			continue ;
		ft_execute(mshell->command);
	}
	tini(mshell);
	free(mshell);
}

static void	init(t_mshell *mshell)
{
	mshell->running = 1;
	mshell->prompt = NULL;
	mshell->line = NULL;
	mshell->path = NULL;
	mshell->env_vars = NULL;
}
/* TODO : getenv */

static void	tini(t_mshell *mshell)
{
	free(mshell->prompt);
	// rl_clear_history();
}
