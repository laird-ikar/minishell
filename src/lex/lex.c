/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:43:32 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/14 08:26:47 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lex.h"

void	set_token(t_token *token, char* content, int type);

void	ft_lex(t_token tokens[MAX_TAB], char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = line;
	ft_bzero(tokens, sizeof (t_token) * MAX_TAB);
	while (i < MAX_TAB && *line)
	{
		if (*line == '|')
			set_token(&tokens[i++], "|", PIPE);
		if (*line == '<')
		{
			if (*(line + 1) == '<')
				set_token(&tokens[i++], "<<", IN_LIMIT);
			if (*(line + 1) == '<')
				line++;
			else
				set_token(&tokens[i++], "<", IN_FILE);
		}
		if (*line == '>')
		{
			if (*(line + 1) == '>')
				set_token(&tokens[i++], ">>", OUT_APPEND);
			if (*(line + 1) == '>')
				line++;
			else
				set_token(&tokens[i++], ">", OUT_FILE);
		}
		line++;
	}
}

void	set_token(t_token *token, char* content, int type)
{
	ft_strlcpy(token->content, content, MAX_TAB);
	token->type = type;
}
