/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:06:36 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/29 09:16:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init(t_mshell *mshell);
static void	tini(t_mshell *mshell);
static void	(*check_function(t_mshell mshell))(t_mshell mshell);
//static void	use_return(int *running);

int	main(void)
{
	t_mshell	*mshell;
	void		(*func)(t_mshell);

	mshell = malloc(sizeof (t_mshell));
	init(mshell);
	while (mshell->running)
	{
		get_prompt(mshell);
		mshell->line = readline(mshell->prompt);
		if (!mshell->line)
		{
			printf("readline error");
			exit(-3);
		}
		add_history(mshell->line);
		func = check_function(mshell);
		if (func)
			func(mshell);
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
}

static void	tini(t_mshell *mshell)
{
	free(mshell->prompt);
}

static void	(*check_function(t_mshell mshell))(t_mshell mshell)
{
	if (!ft_strncmp(line, "exit", 4))
		return (ft_exit);

	else if (!ft_strncmp(mshell->line, "pwd", 3))
		return (ft_pwd);
	else if (ft_sp_null(mshell->line))
		;
	else
		printf("No such command : %s\n", line);
	return(NULL);
}

// static void	use_return(int *running)
// {
// 	int			res;
//
// 	wait(&res);
// 	if (WEXITSTATUS(res) == 42)
// 		*running = 0;
// }
