/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:35:17 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/06 12:08:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lex.h"

static void	unsplit(char **split, char content[MAX_TAB]);
static void	check_splits(char **split, t_mshell *mshell, int k);

void	set_token(t_token *token, char *content, int type)
{
	ft_strlcpy(token->content, content, MAX_TAB);
	token->type = type;
}

int	is_cmd_char(char c)
{
	return (ft_isprint(c) && c != '|' && c != '>' && c != '<'
		&& c != ' ' && c != '\'' && c != '\"');
}

void	expand(t_mshell *mshell, t_token token[MAX_TAB])
{
	int		i;
	int		k;
	char	**split;

	i = 0;
	while (i < MAX_TAB)
	{
		if (token[i].type == ENV_VAR)
			ft_strlcpy(token[i].content,
				ft_getenv(mshell, token[i].content), MAX_TAB);
		if (token[i].type == DOUBLE_QUOTE_STR)
		{
			split = ft_split(token[i].content, ' ');
			k = -1;
			while (split[++k])
			{
				check_splits(split, mshell, k);
			}
			unsplit(split, token[i].content);
		}
		i++;
	}
}

static void	check_splits(char **split, t_mshell *mshell, int k)
{
	char	*tmp;

	if (split[k][0] == '$')
	{
		tmp = ft_getenv(mshell, split[k] + 1);
		if (tmp)
			free(split[k]);
		if (tmp)
			split[k] = ft_strdup(tmp);
		else
			split[k][0] = '\0';
	}
}

static void	unsplit(char **split, char content[MAX_TAB])
{
	char	*tmp;
	int		i;

	tmp = ft_tabjoin(split, " ");
	ft_strlcpy(content, tmp, MAX_TAB);
	free(tmp);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
