/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:35:17 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/22 10:17:37 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lex.h"

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

	i = 0;
	while (i < MAX_TAB || token[i].type != VOID)
	{
		if (token[i].type == ENV_VAR)
			token[i].content = ft_getenv(mshell, token[i].content);
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
	}
}

static void	unsplit(char **split, char *content)
{
	char	*tmp;

	tmp = ft_tabjoin(split, ' ');
	ft_strlcpy(content, tmp, MAX_TAB);
	free(tmp);
	ft_freen(split, 2);
}
