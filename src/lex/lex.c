/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:43:32 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/14 09:44:52 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lex.h"

static void	chevrons(char **line, t_token **token, int *i);
static void	var(char **line, t_token **tokens, int *i);
static void	quotes(char **line, t_token **tokens, int *i);

void	ft_lex(t_token tokens[MAX_TAB], char *line)
{
	int		i;
	char	word[MAX_TAB];
	int		j;

	i = 0;
	ft_bzero(tokens, sizeof (t_token) * MAX_TAB);
	while (i < MAX_TAB && *line)
	{
		if (*line == '|')
			set_token(&tokens[i++], "|", PIPE);
		chevrons(&line, &tokens, &i);
		var(&line, &tokens, &i);
		quotes(&line, &tokens, &i);
		if (is_cmd_char(*line))
		{
			ft_bzero(word, MAX_TAB);
			j = 0;
			while (*line && is_cmd_char(*line) && j < MAX_TAB)
				word[j++] = *(line++);
			line--;
			set_token(&tokens[i++], word, WORD);
		}
		line++;
	}
}

static void	chevrons(char **line, t_token **tokens, int *i)
{
	if (**line == '<')
	{
		if (*(*line + 1) == '<')
			set_token(&(*tokens)[(*i)++], "<<", IN_LIMIT);
		if (*(*line + 1) == '<')
			(*line)++;
		else
			set_token(&(*tokens)[(*i)++], "<", IN_FILE);
	}
	if (**line == '>')
	{
		if (*(*line + 1) == '>')
			set_token(&(*tokens)[(*i)++], ">>", OUT_APPEND);
		if (*(*line + 1) == '>')
			(*line)++;
		else
			set_token(&(*tokens)[(*i)++], ">", OUT_FILE);
	}
}

static void	quotes(char **line, t_token **tokens, int *i)
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
		set_token(&(*tokens)[(*i)++], word, SINGLE_QUOTE_STR);
	}
	if (**line == '\"')
	{
		(*line)++;
		ft_bzero(word, MAX_TAB);
		j = 0;
		while (**line != '\"' && **line && j < MAX_TAB)
			word[j++] = *((*line)++);
		set_token(&(*tokens)[(*i)++], word, DOUBLE_QUOTE_STR);
	}
}

static void	var(char **line, t_token **tokens, int *i)
{
	int		j;
	char	word[MAX_TAB];

	if (**line == '$')
	{
		if (*(++(*line)) == ' ')
		{
			set_token(&(*tokens)[(*i)++], "$", WORD);
		}
		else
		{
			ft_bzero(word, MAX_TAB);
			j = 0;
			while (**line != ' ' && **line && j < MAX_TAB)
				word[j++] = *((*line)++);
			set_token(&(*tokens)[(*i)++], word, ENV_VAR);
		}
	}
}
