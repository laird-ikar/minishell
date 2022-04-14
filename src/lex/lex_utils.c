/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:35:17 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/14 09:47:11 by bguyot           ###   ########.fr       */
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
