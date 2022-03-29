/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:06:36 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/28 16:56:25 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init(t_mshell *mshell);
static void	tini(t_mshell *mshell);
static void	check_function(char *line);
//static void	use_return(int *running);

void 	check_leaks();

int	main(void)
{
	t_mshell	*mshell;
	int			pid;
	int			res;
char	*tmp;

	mshell = malloc(sizeof (mshell));
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
		pid = fork();
		if (pid < 0)
			perror("Error (☞ ಠ_ಠ)☞ ");
		if (pid == 0)
		{
			tmp = mshell->line;
			check_function(tmp);
			exit(0);
		}
		else{
			//use_return(&mshell->running);
			wait(&res);
			if (WEXITSTATUS(res) == 42)
				mshell->running = 0;
			}
	}
	tini(mshell);
	free(mshell);
	check_leaks();//TEST
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

static void	check_function(char *line)
{
	printf("%s\n", line);
	if (!ft_strncmp(line, "exit", 4))
		ft_exit();
	/**/
	// else if (!ft_strcmp(mshell->line, ""))
	// 	;
	else
		printf("No such command : %s\n", line);
	printf("MOMAN G FINI\n");
}

// static void	use_return(int *running)
// {
// 	int			res;
//
// 	wait(&res);
// 	if (WEXITSTATUS(res) == 42)
// 		*running = 0;
// }
