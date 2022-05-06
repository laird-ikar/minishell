/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:43:32 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/06 12:08:08 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lex.h"

static void	chevrons(char **line, t_token **token, int *i);
static void	var(char **line, t_token **token, int *i);
static void	quotes(char **line, t_token **token, int *i);
static void	words(char **line, t_token **token, int *i);

void	ft_lex(t_mshell *mshell, t_token token[MAX_TAB], char *line)
{
	int		i;

	i = 0;
	ft_bzero(token, sizeof (t_token) * MAX_TAB);
	while (i < MAX_TAB && *line)
	{
		if (*line == '|')
			set_token(&token[i++], "|", PIPE);
		chevrons(&line, &token, &i);
		var(&line, &token, &i);
		quotes(&line, &token, &i);
		words(&line, &token, &i);
		if (*line)
			line++;
	}
	expand(mshell, token);
}

static void	chevrons(char **line, t_token **token, int *i)
{
	if (**line == '<')
	{
		if (*(*line + 1) == '<')
			set_token(&(*token)[(*i)++], "<<", IN_LIMIT);
		if (*(*line + 1) == '<')
			(*line)++;
		else
			set_token(&(*token)[(*i)++], "<", IN_FILE);
	}
	if (**line == '>')
	{
		if (*(*line + 1) == '>')
			set_token(&(*token)[(*i)++], ">>", OUT_APPEND);
		if (*(*line + 1) == '>')
			(*line)++;
		else
			set_token(&(*token)[(*i)++], ">", OUT_FILE);
	}
}

static void	quotes(char **line, t_token **token, int *i)
{
	int		j;
	char	word[MAX_TAB];

	if (**line == '\'')
	{
		(*line)++;
		ft_bzero(word, MAX_TAB);
		j = 0;
		while (**line != '\'' && **line && j < MAX_TAB)
			word[j++] = *((*line)++);
		set_token(&(*token)[(*i)++], word, SINGLE_QUOTE_STR);
	}
	if (**line == '\"')
	{
		(*line)++;
		ft_bzero(word, MAX_TAB);
		j = 0;
		while (**line != '\"' && **line && j < MAX_TAB)
			word[j++] = *((*line)++);
		set_token(&(*token)[(*i)++], word, DOUBLE_QUOTE_STR);
	}
}

static void	var(char **line, t_token **token, int *i)
{
	int		j;
	char	word[MAX_TAB];

	if (**line == '$')
	{
		if (*(++(*line)) == ' ')
		{
			set_token(&(*token)[(*i)++], "$", WORD);
		}
		else
		{
			ft_bzero(word, MAX_TAB);
			j = 0;
			while (**line != ' ' && **line && j < MAX_TAB)
				word[j++] = *((*line)++);
			set_token(&(*token)[(*i)++], word, ENV_VAR);
		}
	}
}

static void	words(char **line, t_token **token, int *i)
{
	int		j;
	char	word[MAX_TAB];

	if (is_cmd_char(**line))
	{
		ft_bzero(word, MAX_TAB);
		j = 0;
		while (*line && is_cmd_char(**line) && j < MAX_TAB)
			word[j++] = *((*line)++);
		(*line)--;
		set_token(&(*token)[(*i)++], word, WORD);
	}
}
