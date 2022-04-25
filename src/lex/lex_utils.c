/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:35:17 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/25 07:59:39 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lex.h"

static void	unsplit(char **split, char *content);

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
	char	*tmp;

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
				if (split[k][0] == '$')
				{
					tmp = ft_getenv(mshell, split[k] + 1);
					free(split[k]);
					split[k] = ft_strdup(tmp);
				}
			}
			unsplit(split, token[i].content);
		}
		i++;
	}
}

static void	unsplit(char **split, char *content)
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
